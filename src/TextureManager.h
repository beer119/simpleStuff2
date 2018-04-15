
#ifndef NUNITS_H
#define NUNITS_H
#include <SDL.h>
#include <string>
#include <map>
class TextureManager
{
	private:
	static TextureManager *m_TextureManager;
TextureManager() {

}

public:
void drawTile(std::string id, int margin, int
spacing, int x, int y, int width, int height, int currentRow,
int currentFrame, SDL_Renderer *pRenderer);
	void clearFromTextureMap(std::string id);
	bool load(std::string fileName,std::string id,SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =	SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int	height, int currentRow, int currentFrame, SDL_Renderer*	pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* getInstance() {

	    return (!m_TextureManager) ?
	    		m_TextureManager = new TextureManager :
	    		m_TextureManager;
	    }

};
#endif
