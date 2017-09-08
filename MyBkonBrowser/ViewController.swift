//
//  ViewController.swift
//  MyBkonBrowser
//
//  Created by Robert Rochford on 7/10/17.
//  Copyright © 2017 Robert Rochford. All rights reserved.
//

import UIKit
import AVKit
import AVFoundation
import CoreLocation

class ViewController: UIViewController, PHYEddystoneManagerDelegate, CLLocationManagerDelegate {
    
    let appID = "yourAppID"
    let awesomeBkonBlue = UIColor(colorLiteralRed: 37.0/255.0, green: 137.0/255.0, blue: 191.0/255.0, alpha: 1.0)
    let navBarColor = UIColor.white
    let myBeaconBorderColor = UIColor.lightGray
    var bkonManager: PHYEddystoneManager!
    
    //Harvesting user location https://www.youtube.com/watch?v=UyiuX8jULF4
    let locationManager = CLLocationManager()
    
    let synthesizer = AVSpeechSynthesizer()
    

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        bkonManager = PHYEddystoneManager(apiKey: appID)
        bkonManager.delegate = self
        //set our app to sort area beacons. This is true by default but for the demo we'll leave it in.
        bkonManager.setDelayedReport(true)
        
        //initializing the delegate for the user location
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
        locationManager.startUpdatingLocation()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if let location = locations.first {
            print("Current location: \(location)")
        } else {
            return
        }
    }
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print("Error finding location: \(error.localizedDescription)")
    }
    
    @IBAction func playVideo(_ sender: Any) {
        
        guard let url = URL(string: "https://devimages.apple.com.edgekey.net/samplecode/avfoundationMedia/AVFoundationQueuePlayer_HLS2/master.m3u8")
            else{
                return
        }
        let player = AVPlayer(url: url)
        // Create a new AVPlayerViewController and pass it a reference to the player.
        let controller = AVPlayerViewController()
        controller.player = player
        
        // Modally present the player and call the player's play() method when complete.
        present(controller, animated: true) {
            player.play()
        }
        
    }

    @IBAction func scanForPWBeacons(_ sender: Any) {
        bkonManager.setBarColor(navBarColor, titleColor: awesomeBkonBlue)
        bkonManager.setCellBarColor(myBeaconBorderColor)
        bkonManager.startScanningForBeacons(inModalView: self)
        printFavTouchPoints()
        
        //let utterance = AVSpeechUtterance(string: "I hear you're interested in Physical TouchPoints. You should look at PHY and their suite of technology for all of your proximity marketing solutions. Ask Chris for more info!")
        //utterance.rate = AVSpeechUtteranceMinimumSpeechRate
        //synthesizer.speak(utterance)
    }
    
    func printFavTouchPoints() {
        let favList = bkonManager.getFavoriteBeacons()
        if favList?.isEmpty == true{
            print("There are no favorite beacons :/")
        }
        else{
            //dump(favList)
            for item in favList!{
                if let myBeacon = item as? PHYEddystoneBeacon{
                    print("Fav Title: " + myBeacon.title + "\nFav Desc: " + myBeacon.desc)
                }
            }
        }
    }

}

