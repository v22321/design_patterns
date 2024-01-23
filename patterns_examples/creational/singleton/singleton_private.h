#ifndef SINGLETON_PRIVATE_H
#define SINGLETON_PRIVATE_H

#include <QMutexLocker>
#include <QDebug>

namespace NSingleton {

class BaseSingleton {
    int32_t m_value;

    static BaseSingleton* m_pInstance;
    static QMutex mutex;

private:
    BaseSingleton() = default;

public:
    BaseSingleton(const BaseSingleton& _other) = delete;
    BaseSingleton& operator=(const BaseSingleton& _other) = delete;

    static BaseSingleton* instance() {
        QMutexLocker locker(&mutex);
        if (!m_pInstance)
        {
            qInfo() << "Create singleton";
            m_pInstance = new BaseSingleton();
        }

        return m_pInstance;
    }

    void init(const uint32_t _initVal) {
        qInfo() << "Value changed";
        m_value = _initVal;
    }

    bool work() {
        qInfo() << "Do something count: " << m_value++;
        return m_value >= 3;
    }
};

BaseSingleton* BaseSingleton::m_pInstance {nullptr};
QMutex BaseSingleton::mutex;

}
#endif // SINGLETON_PRIVATE_H
