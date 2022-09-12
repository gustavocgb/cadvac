QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    lib/hpp/dataBase.h \
    lib/hpp/dataBase_impl.h \
    lib/hpp/user.h \
    lib/hpp/user_impl.h \
    lib/hpp/patient.h \
    lib/hpp/patient_impl.h \
    lib/hpp/posts.h \
    lib/hpp/posts_impl.h \
    dashboard.h \
    login.h \
    nurseview.h \
    patientvaccineview.h \
    patientview.h \
    postsview.h \
    search.h \
    usermanagement.h \
    vaccine.h \
    vaccineview.h


SOURCES += \
    lib/cpp/dataBase_impl.cpp \
    lib/cpp/user_impl.cpp \
    lib/cpp/patient_impl.cpp \
    lib/cpp/posts_impl.cpp \
    dashboard.cpp \
    login.cpp \
    main.cpp \
    nurseview.cpp \
    patientvaccineview.cpp \
    patientview.cpp \
    postsview.cpp \
    search.cpp \
    usermanagement.cpp \
    vaccine.cpp \
    vaccineview.cpp

FORMS += \
    dashboard.ui \
    login.ui \
    nurseview.ui \
    patientvaccineview.ui \
    patientview.ui \
    postsview.ui \
    search.ui \
    usermanagement.ui \
    vaccine.ui \
    vaccineview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
