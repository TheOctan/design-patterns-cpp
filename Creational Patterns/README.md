## Порождающие паттерны

Порождающие паттерны проектирования предназначены для создания объектов, позволяя системе оставаться независимой как от самого процесса порождения,
так и от типов порождаемых объектом

* Паттерн [Factory Method] развивает тему фабрики объектов дальше, перенося создание объектов в специально предназначенные для этого классы.
В его классическом варианте вводится полиморфный класс Factory, в котором определяется интерфейс фабричного метода,
а ответственность за создание объектов конкретных классов переносится на производные от Factory классы, в которых этот метод переопределяется.

* Паттерн [Abstract Factory] использует несколько фабричных методов и предназначен для создания целого семейства или группы взаимосвязных объектов.

* Паттерн [Builder] определяет процесс поэтапного конструирования сложного объекта, в результате которого могут получаться разные представления этого объекта.

* Паттерн [Prototype] создаёт новые объекты с помощью прототипов. Прототип - некоторый объект, умеющий создавать по запросу копию самого себя.

* Паттерн [Singleton] контролирует создание единственного экземпляра некоторого класса и предоставляет доступ к нему.

* Паттерн [Object Pool] используется в случае, когда создание объекта требует больших затрат
или может быть создано только ограниченное количество объектов некоторого класса.

Новичкам можно рекомендовать изучение порождающих паттернов в следующей последовательности:
[Singleton], [Factory Method], [Abstract Factory], [Prototype], остальные [паттерны].

### References

[Порождающие паттерны]

[Порождающие паттерны]: http://cpp-reference.ru/patterns/creational-patterns/

[паттерны]: https://github.com/AlvinGames/design-patterns-cpp

[Factory Method]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Factory-Method
[Abstract Factory]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Abstract-Factory
[Builder]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Builder
[Prototype]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Prototype
[Singleton]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Singleton
[Object Pool]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Object-Pool
