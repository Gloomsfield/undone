// amory acosta - copyright 2024

#pragma once

#include "CoreMinimal.h"

#include <string>
#include <vector>

enum EventType {
	DUMMY_EVENT,
};

class UNDONE_API Event {
public:
	Event();
	~Event();

	const virtual EventType type() const { return EventType::DUMMY_EVENT; }
	const virtual std::string name() const { return "Dummy"; }
	const virtual std::string description() const { return "A dummy event"; }
};

class UNDONE_API Observer {
public:
	Observer();
	~Observer();

	virtual void on_notification(const Event & e);
};

class UNDONE_API Publisher {
public:
	Publisher();
	~Publisher();

	std::vector<Observer> observers;

	void notify_observers(const Event & e);

	void subscribe(Observer & observer);
	void unsubscribe(Observer & observer);
};
