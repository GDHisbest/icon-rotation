#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    struct Fields {
        float m_customRotation = 0.0f;
    };

    void update(float dt) {
        PlayerObject::update(dt);

        // Читаем скорость из настроек
        double speed = Mod::get()->getSettingValue<double>("rotation-speed");

        // Крутим на 360 градусов в секунду при speed = 1.0
        m_fields->m_customRotation += static_cast<float>(speed) * 360.0f * dt;

        // Держим угол в диапазоне 0-360
        while (m_fields->m_customRotation >= 360.0f) {
            m_fields->m_customRotation -= 360.0f;
        }
        while (m_fields->m_customRotation < 0.0f) {
            m_fields->m_customRotation += 360.0f;
        }

        // Принудительно ставим вращение
        this->setRotation(m_fields->m_customRotation);
    }
};
