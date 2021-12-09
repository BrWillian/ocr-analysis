#-------------------------------------------------
#
# Project created by QtCreator 2021-12-02T09:46:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ocr-Analysis
TEMPLATE = app
win32:RC_ICONS += "res/icon.png"

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

LIBS += \
        ./libdarknet.so \
        /opt/opencv/build/lib/libade.a \
        /opt/opencv/build/lib/libopencv_aruco.so \
        /opt/opencv/build/lib/libopencv_aruco.so.4.5 \
        /opt/opencv/build/lib/libopencv_aruco.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_bgsegm.so \
        /opt/opencv/build/lib/libopencv_bgsegm.so.4.5 \
        /opt/opencv/build/lib/libopencv_bgsegm.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_bioinspired.so \
        /opt/opencv/build/lib/libopencv_bioinspired.so.4.5 \
        /opt/opencv/build/lib/libopencv_bioinspired.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_calib3d.so \
        /opt/opencv/build/lib/libopencv_calib3d.so.4.5 \
        /opt/opencv/build/lib/libopencv_calib3d.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_ccalib.so \
        /opt/opencv/build/lib/libopencv_ccalib.so.4.5 \
        /opt/opencv/build/lib/libopencv_ccalib.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_core.so \
        /opt/opencv/build/lib/libopencv_core.so.4.5 \
        /opt/opencv/build/lib/libopencv_core.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_datasets.so \
        /opt/opencv/build/lib/libopencv_datasets.so.4.5 \
        /opt/opencv/build/lib/libopencv_datasets.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_dpm.so \
        /opt/opencv/build/lib/libopencv_dpm.so.4.5 \
        /opt/opencv/build/lib/libopencv_dpm.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_face.so \
        /opt/opencv/build/lib/libopencv_face.so.4.5 \
        /opt/opencv/build/lib/libopencv_face.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_features2d.so \
        /opt/opencv/build/lib/libopencv_features2d.so.4.5 \
        /opt/opencv/build/lib/libopencv_features2d.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_flann.so \
        /opt/opencv/build/lib/libopencv_flann.so.4.5 \
        /opt/opencv/build/lib/libopencv_flann.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_freetype.so \
        /opt/opencv/build/lib/libopencv_freetype.so.4.5 \
        /opt/opencv/build/lib/libopencv_freetype.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_fuzzy.so \
        /opt/opencv/build/lib/libopencv_fuzzy.so.4.5 \
        /opt/opencv/build/lib/libopencv_fuzzy.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_gapi.so \
        /opt/opencv/build/lib/libopencv_gapi.so.4.5 \
        /opt/opencv/build/lib/libopencv_gapi.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_hfs.so \
        /opt/opencv/build/lib/libopencv_hfs.so.4.5 \
        /opt/opencv/build/lib/libopencv_hfs.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_highgui.so \
        /opt/opencv/build/lib/libopencv_highgui.so.4.5 \
        /opt/opencv/build/lib/libopencv_highgui.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_imgcodecs.so \
        /opt/opencv/build/lib/libopencv_imgcodecs.so.4.5 \
        /opt/opencv/build/lib/libopencv_imgcodecs.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_img_hash.so \
        /opt/opencv/build/lib/libopencv_img_hash.so.4.5 \
        /opt/opencv/build/lib/libopencv_img_hash.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_imgproc.so \
        /opt/opencv/build/lib/libopencv_imgproc.so.4.5 \
        /opt/opencv/build/lib/libopencv_imgproc.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_intensity_transform.so \
        /opt/opencv/build/lib/libopencv_intensity_transform.so.4.5 \
        /opt/opencv/build/lib/libopencv_intensity_transform.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_line_descriptor.so \
        /opt/opencv/build/lib/libopencv_line_descriptor.so.4.5 \
        /opt/opencv/build/lib/libopencv_line_descriptor.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_ml.so \
        /opt/opencv/build/lib/libopencv_ml.so.4.5 \
        /opt/opencv/build/lib/libopencv_ml.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_objdetect.so \
        /opt/opencv/build/lib/libopencv_objdetect.so.4.5 \
        /opt/opencv/build/lib/libopencv_objdetect.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_optflow.so \
        /opt/opencv/build/lib/libopencv_optflow.so.4.5 \
        /opt/opencv/build/lib/libopencv_optflow.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_phase_unwrapping.so \
        /opt/opencv/build/lib/libopencv_phase_unwrapping.so.4.5 \
        /opt/opencv/build/lib/libopencv_phase_unwrapping.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_photo.so \
        /opt/opencv/build/lib/libopencv_photo.so.4.5 \
        /opt/opencv/build/lib/libopencv_photo.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_plot.so \
        /opt/opencv/build/lib/libopencv_plot.so.4.5 \
        /opt/opencv/build/lib/libopencv_plot.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_quality.so \
        /opt/opencv/build/lib/libopencv_quality.so.4.5 \
        /opt/opencv/build/lib/libopencv_quality.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_rapid.so \
        /opt/opencv/build/lib/libopencv_rapid.so.4.5 \
        /opt/opencv/build/lib/libopencv_rapid.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_reg.so \
        /opt/opencv/build/lib/libopencv_reg.so.4.5 \
        /opt/opencv/build/lib/libopencv_reg.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_rgbd.so \
        /opt/opencv/build/lib/libopencv_rgbd.so.4.5 \
        /opt/opencv/build/lib/libopencv_rgbd.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_saliency.so \
        /opt/opencv/build/lib/libopencv_saliency.so.4.5 \
        /opt/opencv/build/lib/libopencv_saliency.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_shape.so \
        /opt/opencv/build/lib/libopencv_shape.so.4.5 \
        /opt/opencv/build/lib/libopencv_shape.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_stereo.so \
        /opt/opencv/build/lib/libopencv_stereo.so.4.5 \
        /opt/opencv/build/lib/libopencv_stereo.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_stitching.so \
        /opt/opencv/build/lib/libopencv_stitching.so.4.5 \
        /opt/opencv/build/lib/libopencv_stitching.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_structured_light.so \
        /opt/opencv/build/lib/libopencv_structured_light.so.4.5 \
        /opt/opencv/build/lib/libopencv_structured_light.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_superres.so \
        /opt/opencv/build/lib/libopencv_superres.so.4.5 \
        /opt/opencv/build/lib/libopencv_superres.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_surface_matching.so \
        /opt/opencv/build/lib/libopencv_surface_matching.so.4.5 \
        /opt/opencv/build/lib/libopencv_surface_matching.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_tracking.so \
        /opt/opencv/build/lib/libopencv_tracking.so.4.5 \
        /opt/opencv/build/lib/libopencv_tracking.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_ts.a \
        /opt/opencv/build/lib/libopencv_videoio.so \
        /opt/opencv/build/lib/libopencv_videoio.so.4.5 \
        /opt/opencv/build/lib/libopencv_videoio.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_video.so \
        /opt/opencv/build/lib/libopencv_video.so.4.5 \
        /opt/opencv/build/lib/libopencv_video.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_videostab.so \
        /opt/opencv/build/lib/libopencv_videostab.so.4.5 \
        /opt/opencv/build/lib/libopencv_videostab.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_xfeatures2d.so \
        /opt/opencv/build/lib/libopencv_xfeatures2d.so.4.5 \
        /opt/opencv/build/lib/libopencv_xfeatures2d.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_ximgproc.so \
        /opt/opencv/build/lib/libopencv_ximgproc.so.4.5 \
        /opt/opencv/build/lib/libopencv_ximgproc.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_xobjdetect.so \
        /opt/opencv/build/lib/libopencv_xobjdetect.so.4.5 \
        /opt/opencv/build/lib/libopencv_xobjdetect.so.4.5.1 \
        /opt/opencv/build/lib/libopencv_xphoto.so \
        /opt/opencv/build/lib/libopencv_xphoto.so.4.5 \
        /opt/opencv/build/lib/libopencv_xphoto.so.4.5.1 \


QMAKE_LFLAGS = -Wl,-rpath,./

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
