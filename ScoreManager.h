#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QList>
#include <QTime>

struct ScoreRecord {
    QString playerName;
    QTime time;
    int height;
    int width;
};

class ScoreManager {
public:
    static ScoreManager& instance() {
        static ScoreManager instance;
        return instance;
    }

    // Empêcher la copie
    ScoreManager(const ScoreManager&) = delete;
    void operator=(const ScoreManager&) = delete;

    //void recordScore(const QString& playerName, const QTime& time, int width, int height);
    QList<ScoreRecord> loadScores() const;
    void saveScores(const QList<ScoreRecord>& scores) const;

    void clearScores(); // Déplacez cette ligne ici pour rendre la méthode publique

private:
    ScoreManager() {} // Constructeur privé pour le singleton
    QList<ScoreRecord> scores; // Liste pour stocker les scores
};

#endif // SCOREMANAGER_H
