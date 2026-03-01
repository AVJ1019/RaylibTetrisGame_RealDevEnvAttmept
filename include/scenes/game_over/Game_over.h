#include "SceneManager.h"

class Game_over : public Scene
{
private:
    int m_score = -1;
    Rectangle m_btn_exit;
public:
    Game_over(AssetMananger*, int);
    ~Game_over() override;
    void update(float dt) override;
    void draw(Renderer *renderer) override;
};