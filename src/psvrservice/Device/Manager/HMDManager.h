#ifndef HMD_MANAGER_H
#define HMD_MANAGER_H

//-- includes -----
#include <memory>
#include <string>
#include <vector>
#include "DeviceTypeManager.h"
#include "DeviceEnumerator.h"
#include "PSVRConfig.h"

//-- typedefs -----
class ServerHMDView;
typedef std::shared_ptr<ServerHMDView> ServerHMDViewPtr;
class TrackerManager;

//-- definitions -----
class HMDManagerConfig : public PSVRConfig
{
public:
    static const int CONFIG_VERSION;

    HMDManagerConfig(const std::string &fnamebase = "HMDManagerConfig");

    virtual const configuru::Config writeToJSON();
    virtual void readFromJSON(const configuru::Config &pt);

    int version;
    int virtual_hmd_count;
};

class HMDManager : public DeviceTypeManager
{
public:
    HMDManager();

    virtual bool startup() override;
    virtual void shutdown() override;

    static const int k_max_devices = PSVRSERVICE_MAX_HMD_COUNT;
    int getMaxDevices() const override
    {
        return HMDManager::k_max_devices;
    }

    ServerHMDViewPtr getHMDViewPtr(int device_id);

    inline const HMDManagerConfig& getConfig() const
    {
        return cfg;
    }

	// Broadcasts new video frame from a single tracker on tracker thread
	void notifyVideoFrameReceived(class ServerTrackerView* tracker_view);

	// Update Pose Filter using update packets from the tracker and IMU threads
	void updatePoseFilters();

protected:
    bool can_update_connected_devices() override;
    class DeviceEnumerator *allocate_device_enumerator() override;
    void free_device_enumerator(class DeviceEnumerator *) override;
    ServerDeviceView *allocate_device_view(int device_id) override;
    int getListUpdatedResponseType() override;

private:
    HMDManagerConfig cfg;
};

#endif // HMD_MANAGER_H
