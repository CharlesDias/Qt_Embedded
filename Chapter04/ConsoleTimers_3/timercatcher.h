#ifndef TIMECATCHER_H
#define TIMECATCHER_H

#include <QObject>
#include <QTimer>

class TimerCatcher : public QObject
{
    Q_OBJECT
public:
    explicit TimerCatcher(QObject *parent = nullptr);

signals:
void newCount (int count);

public slots:
    void catchExpiredTimer();   ///< called when m_timer timesout
    void printCountDirect(int count);   ///< direct connection print the count value
    void printCountQueued(int count);   ///< queued print the count value

private:
    QTimer  m_timer;            ///< my timer
    int     m_count;            ///< my count
};

#endif // TIMECATCHER_H
