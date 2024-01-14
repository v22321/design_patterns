#ifndef SINGLETON_EXTRA_H
#define SINGLETON_EXTRA_H

#include "cstdint"
#include <QMutex>
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
        if (m_pInstance == nullptr)
        {
            qInfo() << "Create singleton";
            m_pInstance = new BaseSingleton();
        }

        qInfo() << "Get singleton";
        return m_pInstance;
    }

    bool work() { qInfo() << "Buisness logic >>>"; return true; }
};

BaseSingleton* BaseSingleton::m_pInstance {nullptr};
QMutex BaseSingleton::mutex;

}
#endif // SINGLETON_EXTRA_H
