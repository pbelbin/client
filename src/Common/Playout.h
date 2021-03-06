#pragma once

#include "Shared.h"

#include <QtCore/QEvent>
#include <QtCore/QString>

class COMMON_EXPORT Playout
{
    public:
        enum class PlayoutType
        {
            Stop = QEvent::User + 110,
            Play = QEvent::User + 120,
            PlayNow = QEvent::User + 130,
            PauseResume = QEvent::User + 140,
            Load = QEvent::User + 150,
            Next = QEvent::User + 160,
            Update = QEvent::User + 170,
            Invoke = QEvent::User + 180,
            Preview = QEvent::User + 190,
            Clear = QEvent::User + 200,
            ClearVideoLayer = QEvent::User + 210,
            ClearChannel = QEvent::User + 220
        };

        static QString toString(Playout::PlayoutType value);
        static QList<Playout::PlayoutType> createConstantList();
        static const QList<Playout::PlayoutType>& enumConstants();
        static Playout::PlayoutType fromString(const QString& value);

    private:
        Playout() {}
};
