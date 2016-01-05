#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QNetworkAccessManager>

namespace Tool {
    class RequestManager
    {
    public:
        RequestManager();
        ~RequestManager();

        void            connectionRequest(const std::string &, const std::string &);
        QNetworkReply   *registrationRequest(const QString &email, const QString &username,
                                        const QString &password);

        static QNetworkAccessManager       *manager;
    };
}

#endif // REQUESTMANAGER_H
