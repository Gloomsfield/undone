// amory acosta - copyright 2024

#pragma once

#include <unordered_map>
#include <functional>
#include <utility>
#include <vector>
#include <string>

class Event {
public:
	const virtual std::string const name() = 0;
};

class Subscriber { };

class Publisher {
	std::unordered_map<Subscriber *, std::vector<const std::string>> subscriber_event_map;
	std::unordered_map<const std::string, std::vector<std::pair<Subscriber *, std::function<void(Event *)>>>> subscriber_callbacks;

public:
	void notify_subscribers(Event * e);

	bool register_subscriber(Subscriber * subscriber, Event * e, std::function<void(Event *)> f);

	bool unregister_subscriber(Subscriber * subscriber);

private:
	void insert_subscriber_callback(Subscriber * subscriber, Event * e, std::function<void(Event *)> f);
};
