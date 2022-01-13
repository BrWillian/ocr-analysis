#-------------------------------------------------
#
# Project created by QtCreator 2021-12-02T09:46:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thundera
TEMPLATE = app

QMAKE_CXXFLAGS_RELEASE = -MT -O2
QMAKE_CFLAGS_RELEASE = -MT -O2

RC_ICONS = "res/icon.ico"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
INCLUDEPATH += C:\opencv\build\include \
               C:\pthreads \
               $$PWD/../../

SOURCES += \
        main.cpp \
        window.cpp \
    file.cpp \
    detect.cpp \
    annotation.cpp

HEADERS += \
        window.h \
    file.h \
    detect.h \
    annotation.h

FORMS += \
        window.ui
        LIBS += $$PWD/libs/pthreadVC.lib
        LIBS += $$PWD/libs/pthreadVC_x64.lib
        LIBS += $$PWD/libs/pthreadVC2.lib
        LIBS += $$PWD/libs/pthreadVCd.lib
        LIBS += $$PWD/libs/pthreadVCd_x64.lib
        LIBS += $$PWD/libs/darknet.lib
        LIBS += $$PWD/libs/opencv_aruco450.lib
        LIBS += $$PWD/libs/opencv_bgsegm450.lib
        LIBS += $$PWD/libs/opencv_bioinspired450.lib
        LIBS += $$PWD/libs/opencv_calib3d450.lib
        LIBS += $$PWD/libs/opencv_ccalib450.lib
        LIBS += $$PWD/libs/opencv_core450.lib
        LIBS += $$PWD/libs/opencv_datasets450.lib
        LIBS += $$PWD/libs/opencv_dnn450.lib
        LIBS += $$PWD/libs/opencv_dnn_objdetect450.lib
        LIBS += $$PWD/libs/opencv_dnn_superres450.lib
        LIBS += $$PWD/libs/opencv_dpm450.lib
        LIBS += $$PWD/libs/opencv_face450.lib
        LIBS += $$PWD/libs/opencv_features2d450.lib
        LIBS += $$PWD/libs/opencv_flann450.lib
        LIBS += $$PWD/libs/opencv_fuzzy450.lib
        LIBS += $$PWD/libs/opencv_gapi450.lib
        LIBS += $$PWD/libs/opencv_hfs450.lib
        LIBS += $$PWD/libs/opencv_highgui450.lib
        LIBS += $$PWD/libs/opencv_imgcodecs450.lib
        LIBS += $$PWD/libs/opencv_imgproc450.lib
        LIBS += $$PWD/libs/opencv_img_hash450.lib
        LIBS += $$PWD/libs/opencv_intensity_transform450.lib
        LIBS += $$PWD/libs/opencv_line_descriptor450.lib
        LIBS += $$PWD/libs/opencv_mcc450.lib
        LIBS += $$PWD/libs/opencv_ml450.lib
        LIBS += $$PWD/libs/opencv_objdetect450.lib
        LIBS += $$PWD/libs/opencv_optflow450.lib
        LIBS += $$PWD/libs/opencv_phase_unwrapping450.lib
        LIBS += $$PWD/libs/opencv_photo450.lib
        LIBS += $$PWD/libs/opencv_plot450.lib
        LIBS += $$PWD/libs/opencv_quality450.lib
        LIBS += $$PWD/libs/opencv_rapid450.lib
        LIBS += $$PWD/libs/opencv_reg450.lib
        LIBS += $$PWD/libs/opencv_rgbd450.lib
        LIBS += $$PWD/libs/opencv_saliency450.lib
        LIBS += $$PWD/libs/opencv_shape450.lib
        LIBS += $$PWD/libs/opencv_stereo450.lib
        LIBS += $$PWD/libs/opencv_stitching450.lib
        LIBS += $$PWD/libs/opencv_structured_light450.lib
        LIBS += $$PWD/libs/opencv_superres450.lib
        LIBS += $$PWD/libs/opencv_surface_matching450.lib
        LIBS += $$PWD/libs/opencv_text450.lib
        LIBS += $$PWD/libs/opencv_tracking450.lib
        LIBS += $$PWD/libs/opencv_ts450.lib
        LIBS += $$PWD/libs/opencv_video450.lib
        LIBS += $$PWD/libs/opencv_videoio450.lib
        LIBS += $$PWD/libs/opencv_videostab450.lib
        LIBS += $$PWD/libs/opencv_xfeatures2d450.lib
        LIBS += $$PWD/libs/opencv_ximgproc450.lib
        LIBS += $$PWD/libs/opencv_xobjdetect450.lib
        LIBS += $$PWD/libs/opencv_xphoto450.lib

