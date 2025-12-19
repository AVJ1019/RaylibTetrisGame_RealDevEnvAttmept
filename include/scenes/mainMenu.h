#include "SceneManager.h"
#include <vector>

class mainMenu : public Scene
{
private:
    std::vector<Rectangle> buttons;
public:
    mainMenu(AssetMananger *am);
    void update(float dt) override;
    void draw(Renderer *renderer) override;
};