#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    void updateRotation(float dt) {
        double speed = Mod::get()->getSettingValue<double>("rotation-speed");
        PlayerObject::updateRotation((1.0f / 60.0f) * static_cast<float>(speed));
    }
};
