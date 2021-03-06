#include "texugo/com/Manager.hpp"
#include "texugo/log/Logger.hpp"
#include <stdexcept>

Manager::Manager(const std::unordered_map<std::string, std::string>& routingAddresses) {
    for (auto& connection : routingAddresses) {
        const std::string name = connection.first;
        const std::string port = connection.second;
        createConnection(name, port);
    }
}

void Manager::createConnection(const std::string& name, const std::string& port) {
    auto it = m_connectionList.find(name);
    if (it == m_connectionList.end()) {
        Connection cnx(name, port);
        m_connectionList.insert({name, cnx});
        Logger::getInstance().logInfo("Connection created | NAME: " + name + " - PORT: " + port);
    } else {
        const std::string errorMessage = "Connection " + name + " already exists";
        Logger::getInstance().logInfo(errorMessage);
        throw std::runtime_error(errorMessage);
    }
}

const std::unordered_map<std::string, Connection> &Manager::getConnectionList() const {
    return m_connectionList;
}
