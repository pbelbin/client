#include "BrightnessCommand.h"

#include <QtCore/QXmlStreamWriter>

BrightnessCommand::BrightnessCommand(QObject* parent)
    : AbstractCommand(parent)
{
}

float BrightnessCommand::getBrightness() const
{
    return this->brightness;
}

int BrightnessCommand::getTransitionDuration() const
{
    return this->transitionDuration;
}

const QString& BrightnessCommand::getTween() const
{
    return this->tween;
}

bool BrightnessCommand::getDefer() const
{
    return this->defer;
}

void BrightnessCommand::setBrightness(float brightness)
{
    this->brightness = brightness;
    emit brightnessChanged(this->brightness);
}

void BrightnessCommand::setTransitionDuration(int transitionDuration)
{
    this->transitionDuration = transitionDuration;
    emit transitionDurationChanged(this->transitionDuration);
}

void BrightnessCommand::setTween(const QString& tween)
{
    this->tween = tween;
    emit tweenChanged(this->tween);
}

void BrightnessCommand::setDefer(bool defer)
{
    this->defer = defer;
    emit deferChanged(this->defer);
}

void BrightnessCommand::readProperties(boost::property_tree::wptree& pt)
{
    AbstractCommand::readProperties(pt);

    setBrightness(pt.get(L"brightness", Mixer::DEFAULT_BRIGHTNESS));
    setTransitionDuration(pt.get(L"transitionDuration", pt.get(L"transtitionDuration", Mixer::DEFAULT_DURATION)));
    setTween(QString::fromStdWString(pt.get(L"tween", Mixer::DEFAULT_TWEEN.toStdWString())));
    setDefer(pt.get(L"defer", Mixer::DEFAULT_DEFER));
}

void BrightnessCommand::writeProperties(QXmlStreamWriter& writer)
{
    AbstractCommand::writeProperties(writer);

    writer.writeTextElement("brightness", QString::number(getBrightness()));
    writer.writeTextElement("transitionDuration", QString::number(getTransitionDuration()));
    writer.writeTextElement("tween", this->getTween());
    writer.writeTextElement("defer", (getDefer() == true) ? "true" : "false");
}
