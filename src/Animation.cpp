#include "Animation.h"

#include "Resources.h"

const auto AnimationTime = sf::seconds(0.2f);

Animation::Animation(const AnimationData& data, CharacterActions action, sf::Sprite& sprite)
    : m_data(data),
    m_dir(action),
    m_sprite(sprite),
    m_hasQueuedAction(false),
    m_isPlayingOnce(false),
    m_playOnce(false)
{
    update();
}

void Animation::playOnce(CharacterActions action)
{
    // Prevent restarting the same animation if it’s already playing once
    if (m_dir == action && m_isPlayingOnce) {
        return;
    }

    // Set the animation to play once
    m_dir = action;
    m_playOnce = true;
    m_isPlayingOnce = true;
    m_hasQueuedAction = false; // Clear any queued action
    update();
}

void Animation::action(CharacterActions action)
{
    // If a playOnce animation is active, queue the new action
    if (m_isPlayingOnce) {
        m_nextAction = action;
        m_hasQueuedAction = true;
        return;
    }

    // Otherwise, set the new action immediately
    m_dir = action;
    m_playOnce = false;       // Set to loop mode
    m_isPlayingOnce = false;  // Clear play-once tracking              
    update();
}
#include <iostream>

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;

        // Check if animation should stop at the last frame when playing once
        if (m_playOnce && m_index >= m_data.m_data.find(m_dir)->second.size()-1)
        {
            m_isPlayingOnce = false;
            switchQueuedAction();
        }
        else
        {
            m_index %= m_data.m_data.find(m_dir)->second.size();  // Looping mode
        }
        update();
    }
}

void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}

void Animation::switchQueuedAction()
{
    if (m_hasQueuedAction)
    {
        m_dir = m_nextAction;
        m_index = 0;
        m_hasQueuedAction = false;
        return;
    }
}
