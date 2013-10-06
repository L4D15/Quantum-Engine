#include "quantum/EventListener.h"

EventListener::EventListener()
{

}

EventListener::~EventListener()
{

}

void EventListener::OnEvent(SDL_Event * event)
{
    switch (event->type)
    {
        case SDL_WINDOWEVENT:
            switch (event->window.type)
            {
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    OnInputFocus();
                    break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    OnInputBlur();
                    break;
                case SDL_WINDOWEVENT_ENTER:
                    OnMouseFocus();
                    break;
                case SDL_WINDOWEVENT_LEAVE:
                    OnMouseBlur();
                    break;
            }

        case SDL_KEYDOWN:
            OnKeyDown(event->key.keysym.sym, event->key.keysym.mod);
            break;

        case SDL_KEYUP:
            OnKeyUp(event->key.keysym.sym, event->key.keysym.mod);
            break;

        case SDL_MOUSEMOTION:
            OnMouseMove(event->motion.x,
                    event->motion.y,
                    event->motion.xrel,
                    event->motion.yrel,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;

        case SDL_MOUSEBUTTONDOWN:
            switch (event->button.button)
            {
                case SDL_BUTTON_LEFT:
                    OnLeftButtonDown(event->button.x, event->button.y);
                    break;

                case SDL_BUTTON_RIGHT:
                    OnRightButtonDown(event->button.x, event->button.y);
                    break;

                case SDL_BUTTON_MIDDLE:
                    OnMiddleButtonDown(event->button.x, event->button.y);
                    break;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            switch (event->button.button)
            {
                case SDL_BUTTON_LEFT:
                    OnLeftButtonUp(event->button.x, event->button.y);
                    break;

                case SDL_BUTTON_RIGHT:
                    OnRightButtonUp(event->button.x, event->button.y);
                    break;

                case SDL_BUTTON_MIDDLE:
                    OnMiddleButtonUp(event->button.x, event->button.y);
                    break;
            }

        case SDL_JOYAXISMOTION:
            OnJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
            break;

        case SDL_JOYBALLMOTION:
            OnJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
            break;

        case SDL_JOYHATMOTION:
            OnJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
            break;

        case SDL_JOYBUTTONDOWN:
            OnJoyButtonDown(event->jbutton.which, event->jbutton.button);
            break;

        case SDL_JOYBUTTONUP:
            OnJoyButtonUp(event->jbutton.which, event->jbutton.button);
            break;

        case SDL_QUIT:
            OnExit();
            break;

        case SDL_SYSWMEVENT:
            // Ignore
            break;

        case SDL_WINDOWEVENT_RESIZED:
            OnResize(event->window.data1, event->window.data2); // TODO: Check this is right
            break;

        case SDL_WINDOWEVENT_EXPOSED:
            OnExpose();
            break;

        default:
            OnUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
            break;
    }
}

void EventListener::OnInputBlur()
{
    // Pure virtual
}

void EventListener::OnInputFocus()
{
    // Pure Virtual
}

void EventListener::OnKeyDown(SDL_Keycode key, Uint16 mod)
{
    // Pure Virtual
}

void EventListener::OnKeyUp(SDL_Keycode key, Uint16 mod)
{
    // Pure virtual
}

void EventListener::OnMouseFocus()
{
    // Pure virtual
}

void EventListener::OnMouseBlur()
{
    // Pure virtual
}

void EventListener::OnMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle)
{
    // Pure virtual
}

void EventListener::OnMouseWheel(bool up, bool down)
{
    // Pure virtual
}

void EventListener::OnLeftButtonDown(int mouseX, int mouseY)
{
    // Pure virtual
}

void EventListener::OnLeftButtonUp(int mouseX, int mouseY)
{
    // Pure virtual
}

void EventListener::OnRightButtonDown(int mouseX, int mouseY)
{
    // Pure virtual
}

void EventListener::OnRightButtonUp(int mouseX, int mouseY)
{
    // Pure virtual
}

void EventListener::OnMiddleButtonDown(int mouseX, int mouseY)
{
    // Pure virtual
}

void EventListener::OnMiddleButtonUp(int mouseX, int mouseY)
{
    // Pure virtual
}

void EventListener::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
    // Pure virtual
}

void EventListener::OnJoyButtonDown(Uint8 which, Uint8 button)
{
    // Pure virtual
}

void EventListener::OnJoyButtonUp(Uint8 which, Uint8 button)
{
    // Pure virtual
}

void EventListener::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
    // Pure virtual
}

void EventListener::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
{
    // Pure virtual
}

void EventListener::OnMinimize()
{
    // Pure virtual
}

void EventListener::OnRestore()
{
    // Pure virtual
}

void EventListener::OnResize(int w, int h)
{
    // Pure virtual
}

void EventListener::OnExpose()
{
    // Pure virtual
}

void EventListener::OnExit()
{
    // Pure virtual
}

void EventListener::OnUser(Uint8 type, int code, void* data1, void* data2)
{
    // Pure virtual
}
