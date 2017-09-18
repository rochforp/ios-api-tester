//
//  PHYCentralManager.h
//  PhySdk
//
//  Created by Beat Zenerino on 6/23/14.
//  Copyright (c) 2014-2016 BKON Connect Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PHYPeripheral.h"

@class PHYPeripheral;
@protocol PHYCentralManagerDelegate;


/**
 * The PHYCentralManager is used to discover BKON hardware and change its
 * parameters.
 */
@interface PHYCentralManager : NSObject

@property (weak, nonatomic) id<PHYCentralManagerDelegate> delegate;

/**
 * Initializes the PHYCentralManager with an App ID. You can generate an
 * App ID on the BKON Platform here https://my.phy.net/apps.
 *
 * @param apiKey The App ID associated with you application
 */
- (id)initWithApiKey:(NSString *)apiKey;

/**
 * Start scanning for BKON brand beacons. An array of beacons is returned through
 * the 'refreshWithBeacons' delegate method.
 */
- (void)startScan;

/**
 * Stop scanning for BKON brand beacons.
 */
- (void)stopScan;

/**
 * Try to connect to a specific BKON brand beacon. This will establish a one-to-one communication
 * channel to the beacon and allow for changing of the beacons parameters.
 *
 * @param beacon A beacon that was returned through the 'refreshWithBeacons' delegate method
 */
- (BOOL)connectToPeripheral:(PHYPeripheral *)beacon;

/**
 * Break down the communcation channel to the beacon.
 */
- (void)cancelCurrentPeripheral;

@end

/**
 * The PHYCentralManagerDelegate is the protocol used to interface with PHYCentralManager.
 */
@protocol PHYCentralManagerDelegate <NSObject>

@optional
/**
 * Returns an array of beacons within proximity of the device.
 *
 * @param manager the manager
 * @param beacons an array of beacons
 */
- (void)centralManager:(PHYCentralManager *)manager refreshWithBeacons:(NSArray *)beacons;

@end
