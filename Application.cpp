//
// Created by volot on 14.03.2022.
//

#include <iostream>
#include "Application.h"
#include "RetailConsumer.h"
#include "WholesaleConsumer.h"
#include "Shop.h"
#include "Store.h"
#include "Truck.h"
#include "GasolineTanker.h"
#include "GlobalProducer.h"
#include "Exception.h"

using namespace std;

Application::Application() {
    consumers = {};
    producers = {};
}

void Application::init() {
    Consumer *c1 = new RetailConsumer("retail1");
    Consumer *c2 = new WholesaleConsumer("wholesale1");
    consumers[c1->getName()] = c1;
    consumers[c2->getName()] = c2;

    Producer *p1 = new Shop("shop1");
    Producer *p2 = new Store("store1");
    p1->addCar(new Truck());
    p1->addCar(new Truck());
    p1->addCar(new GasolineTanker());
    p2->addCar(new Truck());
    p2->addCar(new GasolineTanker());
    p2->addCar(new GasolineTanker());
    producers[p1->getName()] = p1;
    producers[p2->getName()] = p2;
    GlobalProducer::init();
}

void Application::start() {
    int input = 0;
    do {
        try {
            showMainMenu();
            cin >> input;
            cout << input << endl;
            switch (input) {
                case 1: {
                    string name;
                    cout << "Enter shop name" << endl;
                    cin >> name;
                    if (name.empty()) {
                        throw Exception("Invalid name");
                    }
                    producers[name] = new Shop(name);
                    cout << "Shop was added" << endl;
                }
                    break;
                case 2: {
                    string name;
                    cout << "Enter store name" << endl;
                    cin >> name;
                    if (name.empty()) {
                        throw Exception("Invalid name");
                    }
                    producers[name] = new Store(name);
                    cout << "Store was added" << endl;
                }
                    break;
                case 3: {
                    string name;
                    cout << "Enter retail consumer name" << endl;
                    cin >> name;
                    if (name.empty()) {
                        throw Exception("Invalid name");
                    }
                    consumers[name] = new RetailConsumer(name);
                    cout << "RetailConsumer was added" << endl;
                }
                    break;
                case 4: {
                    string name;
                    cout << "Enter wholesale consumer name" << endl;
                    cin >> name;
                    if (name.empty()) {
                        throw Exception("Invalid name");
                    }
                    consumers[name] = new WholesaleConsumer(name);
                    cout << "WholesaleConsumer was added" << endl;
                }
                    break;
                case 5: {
                    string name;
                    cout << "Enter Producer name" << endl;
                    cin >> name;
                    delete producers[name];
                    cout << "Producer was deleted" << endl;
                }
                    break;
                case 6: {
                    string name;
                    cout << "Enter Consumer name" << endl;
                    cin >> name;
                    delete consumers[name];
                    cout << "Consumer was deleted" << endl;
                }
                    break;
                case 7: {
                    string name;
                    int i;
                    cout << "Enter Producer name" << endl;
                    cin >> name;
                    cout << "1 - Truck" << endl
                         << "2 - Gasoline Tanker" << endl;
                    cin >> i;
                    if (1 != i && 2 != i) {
                        throw Exception("Invalid input");
                    }
                    if (producers.count(name) == 0) {
                        throw Exception("There is no such producer name");
                    }
                    if (i == 1) {
                        producers[name]->addCar(new Truck());
                    } else {
                        producers[name]->addCar(new GasolineTanker());
                    }
                    cout << "Car was added" << endl;
                }
                    break;
                case 8: {
                    string productName;
                    unsigned int amount;
                    string producer;
                    cout << "Enter product name" << endl;
                    cin >> productName;
                    cout << "Enter amount" << endl;
                    cin >> amount;
                    cout << "Enter producer name" << endl;
                    cin >> producer;
                    if (producer.empty() || productName.empty()) {
                        throw Exception("Invalid input");
                    }
                    if (producers.count(producer) == 0) {
                        throw Exception("There is no such producer name");
                    }
                    GlobalProducer::sendProducts(*producers[producer], productName, amount);
                }
                    break;
                case 9: {
                    string producer;
                    cout << "Enter producer name" << endl;
                    cin >> producer;
                    string consumer;
                    cout << "Enter consumer name" << endl;
                    cin >> consumer;
                    string product;
                    cout << "Enter product name" << endl;
                    cin >> product;
                    unsigned int amount;
                    cout << "Enter amount" << endl;
                    cin >> amount;
                    if (producer.empty() || product.empty() || consumer.empty()) {
                        throw Exception("Invalid input");
                    }
                    if (producers.count(producer) == 0 || consumers.count(consumer) == 0) {
                        throw Exception("There is no such producer/consumer name");
                    }
                    producers[producer]->sendProductBatch(*consumers[consumer], product, amount);
                }
                    break;
                case 10: {
                    string producer;
                    cout << "Enter producer name" << endl;
                    cin >> producer;
                    if (producer.empty()) {
                        throw Exception("Invalid input");
                    }
                    if (producers.count(producer) == 0) {
                        throw Exception("There is no such producer name");
                    }
                    producers[producer]->removeLastCar();
                    cout << "Last car was removed from " << producer;
                }
                    break;
                case 11: {
                    string name;
                    cout << "Enter producer name" << endl;
                    cin >> name;
                    if (name.empty()) {
                        throw Exception("Invalid input");
                    }
                    if (producers.count(name) == 0) {
                        throw Exception("There is no such producer name");
                    }
                    Producer *p = producers[name];
                    cout << "Producer:" << endl
                         << "name - " << p->getName() << endl
                         << "type - " << p->getType() << endl;
                    for (Car *c: p->getCars()) {
                        cout << c->getName() << endl;
                    }
                    for (pair<string, unsigned int> pair: p->getProducts()) {
                        cout << pair.first << " - " << pair.second << endl;
                    }
                }
                    break;
                case 12: {
                    string name;
                    cout << "Enter consumer name" << endl;
                    cin >> name;
                    if (name.empty()) {
                        throw Exception("Invalid input");
                    }
                    if (consumers.count(name) == 0) {
                        throw Exception("There is no such producer name");
                    }
                    Consumer *p = consumers[name];
                    cout << "Producer:" << endl
                         << "name - " << p->getName() << endl
                         << "type - " << p->getType() << endl;
                    for (pair<string, unsigned int> pair: p->getProducts()) {
                        cout << pair.first << " - " << pair.second << endl;
                    }
                }
                    break;
                default:
                    continue;
            }
        } catch (Exception e) {
            cout << "-------" << endl << "Exception: " << e.getMessage() << endl << "-------" << endl;
        } catch (std::exception &e) {
            cout << e.what() << endl;
        }
    } while (input != 0);
    GlobalProducer::end();
}

void Application::showMainMenu() {
    cout << "0 - Exit" << endl
         << "1 - Add Shop" << endl
         << "2 - Add Store" << endl
         << "3 - Add Retail Customer" << endl
         << "4 - Add Wholesale Customer" << endl
         << "5 - Remove Producer" << endl
         << "6 - Remove Consumer" << endl
         << "7 - Add Car to Producer" << endl
         << "8 - Add product to Producer" << endl
         << "9 - Send product from Producer to Consumer" << endl
         << "10 - Remove last Car from Producer" << endl
         << "11 - Show Producer info" << endl
         << "12 - Show Consumer info" << endl;
}

Application::~Application() {
    for (auto i: consumers) {
        delete &i;
    }
    for (auto i: producers) {
        delete &i;
    }
    producers.clear();
    consumers.clear();
}
