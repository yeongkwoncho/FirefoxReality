#ifndef DEVICE_DELEGATE_DOT_H
#define DEVICE_DELEGATE_DOT_H

#include "vrb/MacroUtils.h"
#include "vrb/Forward.h"

#include <memory>

class DeviceDelegate;
typedef std::shared_ptr<DeviceDelegate> DeviceDelegatePtr;

class DeviceDelegate {
public:
  enum class CameraEnum { Left, Right };
  virtual vrb::CameraPtr GetCamera(const CameraEnum aWhich) = 0;
  virtual int32_t GetControllerCount() const = 0;
  virtual const std::string GetControllerModelName(const int32_t aWhichContorller) const = 0;
  virtual void ProcessEvents() = 0;
  virtual const vrb::Matrix& GetControllerTransform(const int32_t aWhichController);
  virtual void StartFrame();
  virtual void BindEye(const CameraEnum aWhich) = 0;
  virtual void EndFrame() = 0;
protected:
  DeviceDelegate() {}
  ~DeviceDelegate() {}
private:
  VRB_NO_DEFAULTS(DeviceDelegate)
};

#endif //  DEVICE_DELEGATE_DOT_H