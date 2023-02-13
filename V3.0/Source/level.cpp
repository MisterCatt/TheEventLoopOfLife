#include "level.h"

void SillyAgent::sense(Level* level)
{
}

void SillyAgent::decide()
{
}

void SillyAgent::act()
{
	if(IsKeyDown(KEY_LEFT))
	{
		position.x -= GetFrameTime() * 1000.f;
	}

	if(IsKeyDown(KEY_RIGHT))
	{
		position.x += GetFrameTime() * 1000.f;
	}

	if(IsKeyDown(KEY_SPACE))
	{
		dead = true; //NOTE(Filippo): This is how you kill an agent! (There is no remove_agent(), or despawn_agent()) 
	}
}

void SillyAgent::draw()
{
	DrawCircle(position.x, position.y, 20, BLUE);
}

Agent* Level::get_agent(int id)
{
	auto agent_iterator = id_to_agent.find(id);
	if(agent_iterator != id_to_agent.end())
	{
		return agent_iterator->second;
	}

	return nullptr;
}

void Level::remove_dead_and_add_pending_agents()
{
	auto agent_iterator = all_agents.begin();
	while(agent_iterator != all_agents.end())
	{
		if((*agent_iterator)->dead)
		{
			id_to_agent.erase((*agent_iterator)->id);
			agent_iterator = all_agents.erase(agent_iterator);
		} else 
		{
			agent_iterator++;
		}
	}

	// This must happen _after_ we remove agents from the vector 'all_agents'.
	// @AddMoreHere
	silly_agents.remove_if([](SillyAgent& a){ return a.dead; });


	// Add all pending agents
	for(Agent* agent: pending_agents)
	{
		last_id += 1;
		agent->id = last_id;

		all_agents.push_back(agent);
		id_to_agent.insert({agent->id, agent});
	}

	pending_agents.clear(); // Important that we clear this, otherwise we'll add the same agents every frame.
}

Agent* Level::spawn_agent(SillyAgent agent)
{
	Agent* result = nullptr;

	silly_agents.push_back(agent);
	result = &silly_agents.back();
	
	pending_agents.push_back(result); // Enqueue it so that it can be added to the level at the beginning of the next frame

	return result;
}

void Level::reset()
{
	// TODO: Implement this yourself, clear all lists and vectors, after that spawn agents

    // this is here just as an example.
    // You should also replace "SillyAgent", that is also just an example.

    auto example = spawn_agent(SillyAgent());
    example->position = {100,100};
}

void Level::update()
{
	remove_dead_and_add_pending_agents();

	for(auto& agent : all_agents)
	{
		// TODO: This piece of code needs to be changed to make sure that sense, decide, act, happen at different frequencies.
		agent->sense(this);
		agent->decide();
		agent->act();
	}
}

void Level::draw()
{
	for(auto& agent : all_agents)
	{
		agent->draw();
	}
}