#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/SliderNode.hpp>

using namespace geode::prelude;

static float g_rotationSpeed = 1.0f;

class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto callback = geode::Function<void(float)>([this](float value) {
            g_rotationSpeed = value;
        });

        auto slider = SliderNode::create(callback, false);
        if (!slider) return;

        slider->setMin(0.0f);
        slider->setMax(5.0f);
        slider->setPercent(g_rotationSpeed / 5.0f);

        auto winSize = CCDirector::get()->getWinSize();
        slider->setPosition({winSize.width - 100.f, 60.f});

        this->addChild(slider);
    }
};

class $modify(MyPlayerObject, PlayerObject) {
    void updateRotation(float dt) {
        PlayerObject::updateRotation((1.0f / 60.0f) * g_rotationSpeed);
    }
};
