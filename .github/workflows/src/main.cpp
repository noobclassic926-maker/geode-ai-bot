#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Хранилище координат для отрисовки
struct ClickPoint {
    float x;
    float y;
};

std::vector<ClickPoint> g_clickPoints;

class $modify(MyBotPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        g_clickPoints.clear();

        // Тестовые координаты: добавляем точки для демонстрации отрисовки
        // В будущем сюда подключается логика симуляции/сканирования m_objects
        g_clickPoints.push_back({ 300.0f, 105.0f });
        g_clickPoints.push_back({ 450.0f, 105.0f });

        return true;
    }

    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);

        // Oтрисовка через Cocos2d DrawNode
        auto drawNode = CCDrawNode::create();
        for (const auto& pt : g_clickPoints) {
            // Рисуем зеленый маркер в точке клика
            drawNode->drawDot(ccp(pt.x, pt.y), 6.0f, ccc4f(0.0f, 1.0f, 0.0f, 0.9f));
        }
        
        if (this->m_objectLayer) {
            this->m_objectLayer->addChild(drawNode);
        }
    }
};

