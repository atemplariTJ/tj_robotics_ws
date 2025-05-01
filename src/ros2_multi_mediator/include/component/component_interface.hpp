#pragma once
#include <memory>

template<typename MsgT>
class ComponentInterface {
public:
    virtual ~ComponentInterface() = default;
    virtual void onMessageReceived(std::shared_ptr<MsgT> msg) = 0;
};

class IErasedComponent {
public:
    virtual ~IErasedComponent() = default;
    virtual void call(void* raw_msg) = 0;
};

template<typename MsgT>
class ComponentWrapper : public IErasedComponent {
public:
    ComponentWrapper(std::shared_ptr<ComponentInterface<MsgT>> impl)
    : impl_(impl) {}

    void call(void* raw_msg) override {
        auto typed_msg = std::shared_ptr<MsgT>(static_cast<MsgT*>(raw_msg));
        impl_->onMessageReceived(typed_msg);
    }

private:
    std::shared_ptr<ComponentInterface<MsgT>> impl_;
};

template class ComponentWrapper<std_msgs::msg::String>;