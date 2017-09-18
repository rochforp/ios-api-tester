//
//  PHYEddystoneBeacon.h
//  PhySdk
//
//  Created by Beat Zenerino on 2/20/16.
//  Copyright © 2016 BKON Connect Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class PHYEddystoneManager;

/**
 * The PHYEddystoneBeacon class defines the properties of an Eddystone URL beacon. You
 * don't create an object from this class. PHYEddystoneBeacon objects are returned
 * from the PHYEddystoneManager through the 'didScanBeacons' or 'didScanBeaconsWithMetadata'
 * delegate method.
 */
@interface PHYEddystoneBeacon : NSObject

@property (nonatomic, strong) CBPeripheral *peripheral;

@property (nonatomic, weak) id delegate;

/**
 * The broadcasted URL for an Eddystone URL beacon. In many cases this is a shortened URL.
 */
@property (nonatomic, strong) NSString *scanUrl;

/**
 * The calibrated tx power from an Eddystone URL beacon frame.
 */
@property (nonatomic, strong) NSNumber *txPowerLevel;

/**
 * The RSSI value of the scan for a given Eddystone beacon.
 */
@property (nonatomic, strong) NSNumber *rssi;

/**
 * Set if the scanUrl was resolved for metadata.
 */
@property (nonatomic, strong) NSString *hasMetadata;

/**
 * The resolved final destination URL of an Eddystone URL beacon.
 */
@property (nonatomic, strong) NSString *destinationUrl;

/**
 * The metadata defined title associated with the destinationUrl.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The url location for retrieving the favicon associated with the destinationUrl.
 */
@property (nonatomic, strong) NSString *faviconUrl;

/**
 * The metadata defined description associated with the destinationUrl.
 */
@property (nonatomic, strong) NSString *desc;

/**
 * The favicon image associated with the destinationUrl.
 */
@property (nonatomic, strong) UIImage *faviconImage;

/**
 * The JSON-LD data associated with the destinationUrl. Can be either
 * an NSDictionary or NSArray.
 */
@property (nonatomic, strong) id jsonLd;

/**
 * The distance between the beacon and the device.
 */
@property (nonatomic, assign) double distance;

/**
 * If a CoverCard is being used for this beacon on the platform, this will be a unique id for the particular CoverCard.
 * If you are using the same CoverCard for multiple beacons, this can be used to eliminate duplicates.
 */
@property (nonatomic, strong) NSString *coverCardId;

/**
 * The type of beacon reported which may be either "BLE", "PersistentAbove" or "PersistentBelow". 
 * This persistent content can be defined on the platform for enterprise tier users by selecting your app, choosing "set destinations", choosing a TouchPointID, 
 * and setting one or many TouchPoints for "Persistent In-App Display".
 */
@property (nonatomic, strong) NSString *beaconType;

/**
 * This beacon has been made a favorite by the user.
 */
@property (nonatomic, assign) Boolean favorite;

/**
 * For getting the header image associated with the destination URL
 */

- (UIImage *)getHeadImage;

@end
