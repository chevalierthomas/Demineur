#include "ScoreManager.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

void ScoreManager::saveScores(const QList<ScoreRecord>& scores) const {
    QJsonArray scoreArray;
    for (const auto& score : scores) {
        QJsonObject scoreObject;
        scoreObject["name"] = score.playerName;
        scoreObject["time"] = score.time.toString();
        scoreObject["height"] = score.height;
        scoreObject["width"] = score.width;
        scoreArray.append(scoreObject);
    }

    QJsonObject rootObject;
    rootObject["scores"] = scoreArray;

    QFile saveFile(QStringLiteral("scores.json"));
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument saveDoc(rootObject);
    saveFile.write(saveDoc.toJson());
}

QList<ScoreRecord> ScoreManager::loadScores() const {
    QList<ScoreRecord> scores;
    QFile loadFile(QStringLiteral("scores.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return scores;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray scoreArray = loadDoc.object()["scores"].toArray();
    for (int i = 0; i < scoreArray.size(); ++i) {
        QJsonObject scoreObject = scoreArray[i].toObject();
        ScoreRecord score;
        score.playerName = scoreObject["name"].toString();
        score.time = QTime::fromString(scoreObject["time"].toString());
        score.height = scoreObject["height"].toInt();
        score.width = scoreObject["width"].toInt();
        scores.append(score);
    }

    return scores;
}

void ScoreManager::clearScores() {
    scores.clear(); // Efface la liste interne des scores

    // Efface le contenu du fichier scores.json
    QFile file(QStringLiteral("scores.json"));
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.close();
    }
}
