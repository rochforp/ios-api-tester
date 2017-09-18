//
//  PHYEddystoneManager.h
//  PhySdk
//
//  Created by Beat Zenerino on 2/11/16.
//  Copyright © 2016 BKON Connect Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PHYEddystoneBeacon;

@protocol PHYEddystoneManagerDelegate;

/**
 * The PHYEddystoneManager class is used to discover Eddystone URL beacons and query their
 * approximate distance to the device.
 */
@interface PHYEddystoneManager : NSObject

@property (weak, nonatomic) id<PHYEddystoneManagerDelegate> delegate;


/**
 * Initializes the PHYEddystoneManager with an App ID. You can obtain an
 * App ID from the BKON Platform https://my.phy.net/apps.
 *
 * @param apiKey The App ID associated with your application
 */
- (id)initWithApiKey:(NSString *)apiKey;

/**
 * Start scanning for BLE Eddystone URL beacons in proximity to the device. After calling this function the
 * PHYEddystoneManager will start returning the broadcast URL for any Eddystone URL beacons found
 * through the delegate function 'didScanBeacons'.
 */
- (void)startScanningForBeacons;

/**
 * Start scanning for BLE Eddystone URL beacons in proximity to the device with metadata. After calling this function the
 * PHYEddystoneManager will start returning metadata for any Eddystone URL beacons found
 * through the delegate function 'didScanBeaconsWithMetadata'.
 */
- (void)startScanningForBeaconsWithMetadata;

/**
 * Start scanning for beacons. After calling this function the
 * PHYEddystoneManager will open a modal window displaying nearby found beacons with the resolved metadata.
 * This modal window contains a pull to refresh as well which clears the list and re-initiates a scan for nearby Eddystone URL beacons.
 * @param vc The modal window will be added to this ViewController
 */
- (void)startScanningForBeaconsInModalView:(UIViewController *)vc;

/**
 * Stops scanning for Eddystone URL beacons.
 */
- (void)stopScanningForBeacons;

/**
 * Start scanning for QR codes. After calling this function the
 * PHYEddystoneManager will open a modal window with a QR code scanner and a view 
 * displaying the found codes. This function currently only supports the scanning of URL based QR codes.
 * @param vc The modal window will be added to this ViewController
 */
- (void)startScanningForQRCodesInModalView:(UIViewController *)vc;

/**
 * Add a user id to the scan URL.
 *
 * @param userId a user id string
 */
- (void)addUserId:(NSString *)userId;

/**
 * Add a tag to the scan URL
 *
 * @param value the value for the tag
 * @param tag the tag
 */
- (void)setValue:(NSString *)value forTag:(NSString *)tag;

/**
 * Remove a tag from the scan URL
 *
 * @param tag a tag
 */
- (void)removeTag:(NSString *)tag;

/**
 * Returns a dictionary of current tags
 */
- (NSDictionary *)allTags;

/**
 * Set initial scan mode to either sort beacons based on proximity or not.
 * If false, then return beacons as soon as they're discovered despite proximity.
 *
 * @param delayReport set initial delay and sort
 *
 * true = wait to gather beacons and sort according to distance before reporting.
 * false = report beacons immediately after they are found.
 */
- (void)setDelayedReport:(Boolean)delayReport;

/**
 * Set the color of the navigation bar and title string in modal views.
 *
 * @param barColor the color for the navigation bar
 * @param titleColor the color for the title string in the navigation bar
 */
- (void)setBarColor:(UIColor *)barColor titleColor:(UIColor *)titleColor;

/**
 * Set the color of the bottom bar of table cells for the modal views.
 *
 * @param cellBarColor the color for the bottom bar
 */
- (void)setCellBarColor:(UIColor *)cellBarColor;

/**
 * Add beacon to favorites.
 *
 * @param beacon this needs to be a beacon from the NSArray returned by the delegate method 'didScanBeaconsWithMetadata'
 */
- (void)addBeaconToFavorites:(PHYEddystoneBeacon *)beacon;

/**
 * Remove beacon from favorites.
 *
 * @param beacon this needs to be a beacon from NSArray returned by 'getFavoriteBeacons'
 */
- (void)removeBeaconFromFavorites:(PHYEddystoneBeacon *)beacon;

/**
 * Get an array of all favorite beacons.
 */
- (NSArray *)getFavoriteBeacons;

@end


/**
 * The PHYEddystoneManagerDelegate is used to listen to beacon events from the
 * PHYEddystoneManager.
 */
@protocol PHYEddystoneManagerDelegate <NSObject>

@optional

/**
 * Invoked when the device enters the proximity of an Eddystone URL beacon.
 *
 * @param manager the PHYEddystoneManager object
 * @param beacons an array of EddystoneBeacon's within proximity of the device
 */
- (void)phyManager:(PHYEddystoneManager *)manager didScanBeacons:(NSArray *)beacons;

/**
 * Invoked when the device enters the proximity of an Eddystone URL beacon.
 *
 * @param manager the PHYEddystoneManager object
 * @param beacons an array of EddystoneBeacon's within proximity of the device
 */
- (void)phyManager:(PHYEddystoneManager *)manager didScanBeaconsWithMetadata:(NSArray *)beacons;

@end
