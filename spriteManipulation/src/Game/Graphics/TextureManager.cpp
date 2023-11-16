#include "TextureManager.h"
#include <iostream>

std::map<std::string, std::unique_ptr<Texture>> TextureManager::textures;

std::string TextureManager::generateKey(const std::string& fileName, const std::string& shaderName) {
    return fileName + "|" + shaderName;  
}

Texture* TextureManager::LoadTexture(const std::string& fileName, SDL_Renderer* renderer, PixelShader shader) {
    std::string key = generateKey(fileName, shader.name);
    if (textures.count(key) > 0) {
        return textures[key].get();
    }
    
    auto tex = std::make_unique<Texture>(renderer);
    tex->load("assets/" + fileName, shader);
    
    textures[key] = std::move(tex);    
    return textures[key].get();
}

void TextureManager::UnloadTexture(const std::string& fileName, const std::string& shaderName) {
    std::string key = generateKey(fileName, shaderName);
    textures.erase(key);
}

Texture* TextureManager::GetTexture(const std::string& fileName, const std::string& shaderName) {
    std::string key = generateKey(fileName, shaderName);
    if(textures.count(key) > 0) {
        return textures[key].get();
    }
    
    return nullptr;
}
