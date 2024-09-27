// amory acosta - copyright 2024

#include "Observer.h"

Event::Event() {

}

Event::~Event() {

}

Observer::Observer() {
 
}

void Observer::on_notification(const Event & e) {
	if (!GEngine) {
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Observer super class received notification: %s", e.name()));
}

Observer::~Observer() {

}

Publisher::Publisher() {

}

void Publisher::notify_observers(const Event & e) {
	for (auto observer = observers.begin(); observer != observers.end(); observer++) {
		(*observer).on_notification(e);
	}
}

void Publisher::subscribe(Observer & observer) {
	observers.push_back(observer);
}

void Publisher::unsubscribe(Observer & observer) {
	for (auto current = observers.begin(); current != observers.end(); current++) {
		if(&(*current) == &observer) {
			observers.erase(current);
		}
	}
}

Publisher::~Publisher() {

}
