# Debugging specifications
The debugging interface should be modular and extensible.

## User scenarios
* The LogContainer should contain at most N messages, as specified by the user.
* The LogContainer interface should enable simple retrieval of the K last messages as a string, or any interval of messages.