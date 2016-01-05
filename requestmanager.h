#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QNetworkAccessManager>

namespace Tool {
    class RequestManager
    {
    public:
        RequestManager();
        ~RequestManager();

        QNetworkReply   *connectionRequest(const QString &, const QString &);
        QNetworkReply   *registrationRequest(const QString &email, const QString &username,
                                        const QString &password);

        QNetworkAccessManager       *manager;
    };
}

#endif // REQUESTMANAGER_H
