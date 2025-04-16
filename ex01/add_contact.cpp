#include <iostream>
#include "Contact.hpp"

static void promptAndSet(const std::string& prompt, void (Contact::*setter)(const))