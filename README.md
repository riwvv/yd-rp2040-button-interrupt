[![GitHub stars](https://img.shields.io/github/stars/riwvv/yd-rp2040-button-interrupt)](https://github.com/riwvv/yd-rp2040-button-interrupt/stargazers)
[![License](https://img.shields.io/badge/License-MIT-blue)](LICENSE)
[![C++](https://img.shields.io/badge/C++-17-blue)](https://isocpp.org/)
[![Pico SDK](https://img.shields.io/badge/Pico%20SDK-2.3.0-green)](https://github.com/raspberrypi/pico-sdk)
[![Platform](https://img.shields.io/badge/Platform-RP2040-orange)](https://www.raspberrypi.com/products/rp2040/)

# Взаимодействие с встроенной пользовательской кнопкой (USR) на Raspberry Pi Pico YD-RP2040
### Реализация IRQ и уведомление о нажатии в консоль по USB

---

## Описание
Простой проект для платы **YD-RP2040**, демонстрирующий:
- Обработку нажатия встроенной пользовательской кнопки **USR** (GPIO24) с использованием аппаратного прерывания **IRQ**.
- Включение/выключение встроенного светодиода GPIO25 при нажатии на 100мс.
- Вывод уведомления `">> Button pressed"` в консоль через USB-порт.

**Не требует пайки или внешних компонентов, использовались только встроенные элементы.**

## Стек
- C++ 17
- Pico SDK

## Лицензия MIT
[LICENSE](LICENSE)
