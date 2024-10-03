// amory acosta - copyright 2024


#include "Observer.h"

void Publisher::notify_subscribers(Event * e) {
	std::vector<std::pair<Subscriber *, std::function<void(Event *)>>> subscriber_callback_pairs;

	auto found_value = subscriber_callbacks.find(e->name());

	if (found_value == subscriber_callbacks.end()) {
		return;
	}

	subscriber_callback_pairs = subscriber_callbacks[e->name()];

	for (std::pair<Subscriber *, std::function<void(Event *)>> subscriber_callback_pair : subscriber_callback_pairs) {
		subscriber_callback_pair.second(e);
	}
}

bool Publisher::register_subscriber(Subscriber * subscriber, Event * e, std::function<void(Event *)> f) {
	auto found_subscriber_value = subscriber_event_map.find(subscriber);

	if (found_subscriber_value != subscriber_event_map.end()) {
		std::vector<const std::string> & event_names = subscriber_event_map[subscriber];

		for (std::string event_name : event_names) {
			if (event_name == e->name()) {
				return false;
			}
		}

		event_names.push_back(e->name());

		insert_subscriber_callback(subscriber, e, f);

		return true;
	}

	subscriber_event_map[subscriber] = { e->name() };

	insert_subscriber_callback(subscriber, e, f);

	return true;
}

bool Publisher::unregister_subscriber(Subscriber * subscriber) {
	auto found_subscriber_value = subscriber_event_map.find(subscriber);

	if (found_subscriber_value == subscriber_event_map.end()) {
		return false;
	}

	for (std::string event_name : subscriber_event_map[subscriber]) {
		auto found_pair_values = subscriber_callbacks.find(event_name);

		if (found_pair_values == subscriber_callbacks.end()) {
			continue;
		}

		std::vector<std::pair<Subscriber *, std::function<void(Event *)>>> & found_pairs = subscriber_callbacks[event_name];

		for (auto pair_iterator = found_pairs.begin(); pair_iterator != found_pairs.end(); pair_iterator++) {
			if (pair_iterator->first == subscriber) {
				found_pairs.erase(pair_iterator);
				break;
			}
		}
	}

	subscriber_event_map.erase(found_subscriber_value);

	return true;
}

void Publisher::insert_subscriber_callback(Subscriber * subscriber, Event * e, std::function<void(Event *)> f) {
	auto found_callback_value = subscriber_callbacks.find(e->name());

	if (found_callback_value == subscriber_callbacks.end()) {
		subscriber_callbacks[e->name()] = { std::pair<Subscriber *, std::function<void(Event *)>>(subscriber, f) };

		return;
	}

	subscriber_callbacks[e->name()].push_back(std::pair<Subscriber *, std::function<void(Event *)>>(subscriber, f));
}
