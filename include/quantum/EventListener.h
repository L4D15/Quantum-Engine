#ifndef EVENTLISTENER_H
#define	EVENTLISTENER_H

#include <SDL2/SDL.h>


class EventListener {
public:
    EventListener();
    virtual ~EventListener();

    virtual void OnEvent(SDL_Event * event);
    virtual void OnInputFocus();
    virtual void OnInputBlur();
    virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
    virtual void OnKeyUp(SDL_Keycode key, Uint16 mod);
    virtual void OnMouseFocus();
    virtual void OnMouseBlur();
    virtual void OnMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle);
    virtual void OnMouseWheel(bool up, bool down);
    virtual void OnLeftButtonDown(int mouseX, int mouseY);
    virtual void OnLeftButtonUp(int mouseX, int mouseY);
    virtual void OnRightButtonDown(int mouseX, int mouseY);
    virtual void OnRightButtonUp(int mouseX, int mouseY);
    virtual void OnMiddleButtonDown(int mouseX, int mouseY);
    virtual void OnMiddleButtonUp(int mouseX, int mouseY);
    virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
    virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
    virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
    virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
    virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
    virtual void OnMinimize();
    virtual void OnRestore();
    virtual void OnResize(int w, int h);
    virtual void OnExpose();
    virtual void OnExit();
    virtual void OnUser(Uint8 type, int code, void * data1, void * data2);

private:

};

#endif	/* EVENT_H */
