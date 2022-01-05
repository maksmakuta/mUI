#include "Canvas.h"
#include "../app/Logger.h"

Canvas::Canvas(Backend mBackend){
    this->backend = mBackend;
    if(this->backend == VK)      this->vk = new VKRenderer();
    else if(this->backend == GL) this->gl = new GLRenderer();
    else Log::onError("Unsupported Backend");
}

Canvas::~Canvas(){

}
