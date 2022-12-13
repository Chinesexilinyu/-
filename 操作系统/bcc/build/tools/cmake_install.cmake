# Install script for directory: /home/seed/Desktop/bcc/tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "argdist" FILES "/home/seed/Desktop/bcc/tools/argdist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "bashreadline" FILES "/home/seed/Desktop/bcc/tools/bashreadline.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "bindsnoop" FILES "/home/seed/Desktop/bcc/tools/bindsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "biolatency" FILES "/home/seed/Desktop/bcc/tools/biolatency.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "biolatpcts" FILES "/home/seed/Desktop/bcc/tools/biolatpcts.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "biosnoop" FILES "/home/seed/Desktop/bcc/tools/biosnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "biotop" FILES "/home/seed/Desktop/bcc/tools/biotop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "bitesize" FILES "/home/seed/Desktop/bcc/tools/bitesize.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "bpflist" FILES "/home/seed/Desktop/bcc/tools/bpflist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "btrfsdist" FILES "/home/seed/Desktop/bcc/tools/btrfsdist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "btrfsslower" FILES "/home/seed/Desktop/bcc/tools/btrfsslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "cachestat" FILES "/home/seed/Desktop/bcc/tools/cachestat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "cachetop" FILES "/home/seed/Desktop/bcc/tools/cachetop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "capable" FILES "/home/seed/Desktop/bcc/tools/capable.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "compactsnoop" FILES "/home/seed/Desktop/bcc/tools/compactsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "cpudist" FILES "/home/seed/Desktop/bcc/tools/cpudist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "cpuunclaimed" FILES "/home/seed/Desktop/bcc/tools/cpuunclaimed.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "criticalstat" FILES "/home/seed/Desktop/bcc/tools/criticalstat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "dbslower" FILES "/home/seed/Desktop/bcc/tools/dbslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "dbstat" FILES "/home/seed/Desktop/bcc/tools/dbstat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "dcsnoop" FILES "/home/seed/Desktop/bcc/tools/dcsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "dcstat" FILES "/home/seed/Desktop/bcc/tools/dcstat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "deadlock" FILES "/home/seed/Desktop/bcc/tools/deadlock.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "dirtop" FILES "/home/seed/Desktop/bcc/tools/dirtop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "drsnoop" FILES "/home/seed/Desktop/bcc/tools/drsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "execsnoop" FILES "/home/seed/Desktop/bcc/tools/execsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "exitsnoop" FILES "/home/seed/Desktop/bcc/tools/exitsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "ext4dist" FILES "/home/seed/Desktop/bcc/tools/ext4dist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "ext4slower" FILES "/home/seed/Desktop/bcc/tools/ext4slower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "filelife" FILES "/home/seed/Desktop/bcc/tools/filelife.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "fileslower" FILES "/home/seed/Desktop/bcc/tools/fileslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "filetop" FILES "/home/seed/Desktop/bcc/tools/filetop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "funccount" FILES "/home/seed/Desktop/bcc/tools/funccount.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "funcinterval" FILES "/home/seed/Desktop/bcc/tools/funcinterval.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "funclatency" FILES "/home/seed/Desktop/bcc/tools/funclatency.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "funcslower" FILES "/home/seed/Desktop/bcc/tools/funcslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "gethostlatency" FILES "/home/seed/Desktop/bcc/tools/gethostlatency.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "hardirqs" FILES "/home/seed/Desktop/bcc/tools/hardirqs.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "inject" FILES "/home/seed/Desktop/bcc/tools/inject.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "killsnoop" FILES "/home/seed/Desktop/bcc/tools/killsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "klockstat" FILES "/home/seed/Desktop/bcc/tools/klockstat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "kvmexit" FILES "/home/seed/Desktop/bcc/tools/kvmexit.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "llcstat" FILES "/home/seed/Desktop/bcc/tools/llcstat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "mdflush" FILES "/home/seed/Desktop/bcc/tools/mdflush.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "memleak" FILES "/home/seed/Desktop/bcc/tools/memleak.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "mountsnoop" FILES "/home/seed/Desktop/bcc/tools/mountsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "mysqld_qslower" FILES "/home/seed/Desktop/bcc/tools/mysqld_qslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "netqtop" FILES "/home/seed/Desktop/bcc/tools/netqtop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "nfsdist" FILES "/home/seed/Desktop/bcc/tools/nfsdist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "nfsslower" FILES "/home/seed/Desktop/bcc/tools/nfsslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "offcputime" FILES "/home/seed/Desktop/bcc/tools/offcputime.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "offwaketime" FILES "/home/seed/Desktop/bcc/tools/offwaketime.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "oomkill" FILES "/home/seed/Desktop/bcc/tools/oomkill.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "opensnoop" FILES "/home/seed/Desktop/bcc/tools/opensnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "pidpersec" FILES "/home/seed/Desktop/bcc/tools/pidpersec.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "profile" FILES "/home/seed/Desktop/bcc/tools/profile.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "readahead" FILES "/home/seed/Desktop/bcc/tools/readahead.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "runqlat" FILES "/home/seed/Desktop/bcc/tools/runqlat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "runqlen" FILES "/home/seed/Desktop/bcc/tools/runqlen.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "runqslower" FILES "/home/seed/Desktop/bcc/tools/runqslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "shmsnoop" FILES "/home/seed/Desktop/bcc/tools/shmsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "slabratetop" FILES "/home/seed/Desktop/bcc/tools/slabratetop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "sofdsnoop" FILES "/home/seed/Desktop/bcc/tools/sofdsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "softirqs" FILES "/home/seed/Desktop/bcc/tools/softirqs.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "solisten" FILES "/home/seed/Desktop/bcc/tools/solisten.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "sslsniff" FILES "/home/seed/Desktop/bcc/tools/sslsniff.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "stackcount" FILES "/home/seed/Desktop/bcc/tools/stackcount.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "statsnoop" FILES "/home/seed/Desktop/bcc/tools/statsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "swapin" FILES "/home/seed/Desktop/bcc/tools/swapin.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "syncsnoop" FILES "/home/seed/Desktop/bcc/tools/syncsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "syscount" FILES "/home/seed/Desktop/bcc/tools/syscount.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpaccept" FILES "/home/seed/Desktop/bcc/tools/tcpaccept.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpconnect" FILES "/home/seed/Desktop/bcc/tools/tcpconnect.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpconnlat" FILES "/home/seed/Desktop/bcc/tools/tcpconnlat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpdrop" FILES "/home/seed/Desktop/bcc/tools/tcpdrop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcplife" FILES "/home/seed/Desktop/bcc/tools/tcplife.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpretrans" FILES "/home/seed/Desktop/bcc/tools/tcpretrans.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcprtt" FILES "/home/seed/Desktop/bcc/tools/tcprtt.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpstates" FILES "/home/seed/Desktop/bcc/tools/tcpstates.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpsubnet" FILES "/home/seed/Desktop/bcc/tools/tcpsubnet.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcpsynbl" FILES "/home/seed/Desktop/bcc/tools/tcpsynbl.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcptop" FILES "/home/seed/Desktop/bcc/tools/tcptop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tcptracer" FILES "/home/seed/Desktop/bcc/tools/tcptracer.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "threadsnoop" FILES "/home/seed/Desktop/bcc/tools/threadsnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tplist" FILES "/home/seed/Desktop/bcc/tools/tplist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "trace" FILES "/home/seed/Desktop/bcc/tools/trace.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "ttysnoop" FILES "/home/seed/Desktop/bcc/tools/ttysnoop.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "vfscount" FILES "/home/seed/Desktop/bcc/tools/vfscount.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "vfsstat" FILES "/home/seed/Desktop/bcc/tools/vfsstat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "virtiostat" FILES "/home/seed/Desktop/bcc/tools/virtiostat.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "wakeuptime" FILES "/home/seed/Desktop/bcc/tools/wakeuptime.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "xfsdist" FILES "/home/seed/Desktop/bcc/tools/xfsdist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "xfsslower" FILES "/home/seed/Desktop/bcc/tools/xfsslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "zfsdist" FILES "/home/seed/Desktop/bcc/tools/zfsdist.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "zfsslower" FILES "/home/seed/Desktop/bcc/tools/zfsslower.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "cobjnew" FILES "/home/seed/Desktop/bcc/tools/cobjnew.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/cobjnew" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uobjnew -l c \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "javacalls" FILES "/home/seed/Desktop/bcc/tools/javacalls.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/javacalls" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ucalls -l java \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "javaflow" FILES "/home/seed/Desktop/bcc/tools/javaflow.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/javaflow" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uflow -l java \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "javagc" FILES "/home/seed/Desktop/bcc/tools/javagc.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/javagc" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ugc -l java \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "javaobjnew" FILES "/home/seed/Desktop/bcc/tools/javaobjnew.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/javaobjnew" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uobjnew -l java \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "javastat" FILES "/home/seed/Desktop/bcc/tools/javastat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/javastat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l java \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "javathreads" FILES "/home/seed/Desktop/bcc/tools/javathreads.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/javathreads" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uthreads -l java \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "nodegc" FILES "/home/seed/Desktop/bcc/tools/nodegc.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/nodegc" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ugc -l node \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "nodestat" FILES "/home/seed/Desktop/bcc/tools/nodestat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/nodestat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l node \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "perlcalls" FILES "/home/seed/Desktop/bcc/tools/perlcalls.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/perlcalls" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ucalls -l perl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "perlflow" FILES "/home/seed/Desktop/bcc/tools/perlflow.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/perlflow" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uflow -l perl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "perlstat" FILES "/home/seed/Desktop/bcc/tools/perlstat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/perlstat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l perl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "phpcalls" FILES "/home/seed/Desktop/bcc/tools/phpcalls.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/phpcalls" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ucalls -l php \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "phpflow" FILES "/home/seed/Desktop/bcc/tools/phpflow.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/phpflow" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uflow -l php \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "phpstat" FILES "/home/seed/Desktop/bcc/tools/phpstat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/phpstat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l php \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "pythoncalls" FILES "/home/seed/Desktop/bcc/tools/pythoncalls.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/pythoncalls" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ucalls -l python \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "pythonflow" FILES "/home/seed/Desktop/bcc/tools/pythonflow.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/pythonflow" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uflow -l python \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "pythongc" FILES "/home/seed/Desktop/bcc/tools/pythongc.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/pythongc" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ugc -l python \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "pythonstat" FILES "/home/seed/Desktop/bcc/tools/pythonstat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/pythonstat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l python \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "reset-trace" FILES "/home/seed/Desktop/bcc/tools/reset-trace.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "rubycalls" FILES "/home/seed/Desktop/bcc/tools/rubycalls.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/rubycalls" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ucalls -l ruby \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "rubyflow" FILES "/home/seed/Desktop/bcc/tools/rubyflow.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/rubyflow" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uflow -l ruby \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "rubygc" FILES "/home/seed/Desktop/bcc/tools/rubygc.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/rubygc" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ugc -l ruby \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "rubyobjnew" FILES "/home/seed/Desktop/bcc/tools/rubyobjnew.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/rubyobjnew" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uobjnew -l ruby \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "rubystat" FILES "/home/seed/Desktop/bcc/tools/rubystat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/rubystat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l ruby \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tclcalls" FILES "/home/seed/Desktop/bcc/tools/tclcalls.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/tclcalls" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ucalls -l tcl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tclflow" FILES "/home/seed/Desktop/bcc/tools/tclflow.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/tclflow" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uflow -l tcl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tclobjnew" FILES "/home/seed/Desktop/bcc/tools/tclobjnew.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/tclobjnew" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/uobjnew -l tcl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE PROGRAM RENAME "tclstat" FILES "/home/seed/Desktop/bcc/tools/tclstat.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(WRITE "$ENV{DESTDIR}/${CMAKE_INSTALL_PREFIX}/share/bcc/tools/tclstat" "#!/bin/bash
lib=$(dirname $0)/lib
$lib/ustat -l tcl \"$@\"
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools" TYPE FILE FILES
    "/home/seed/Desktop/bcc/tools/deadlock.c"
    "/home/seed/Desktop/bcc/tools/netqtop.c"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bcc/tools/doc" TYPE FILE FILES
    "/home/seed/Desktop/bcc/tools/argdist_example.txt"
    "/home/seed/Desktop/bcc/tools/bashreadline_example.txt"
    "/home/seed/Desktop/bcc/tools/bindsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/biolatency_example.txt"
    "/home/seed/Desktop/bcc/tools/biolatpcts_example.txt"
    "/home/seed/Desktop/bcc/tools/biosnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/biotop_example.txt"
    "/home/seed/Desktop/bcc/tools/bitesize_example.txt"
    "/home/seed/Desktop/bcc/tools/bpflist_example.txt"
    "/home/seed/Desktop/bcc/tools/btrfsdist_example.txt"
    "/home/seed/Desktop/bcc/tools/btrfsslower_example.txt"
    "/home/seed/Desktop/bcc/tools/cachestat_example.txt"
    "/home/seed/Desktop/bcc/tools/cachetop_example.txt"
    "/home/seed/Desktop/bcc/tools/capable_example.txt"
    "/home/seed/Desktop/bcc/tools/cobjnew_example.txt"
    "/home/seed/Desktop/bcc/tools/compactsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/cpudist_example.txt"
    "/home/seed/Desktop/bcc/tools/cpuunclaimed_example.txt"
    "/home/seed/Desktop/bcc/tools/criticalstat_example.txt"
    "/home/seed/Desktop/bcc/tools/cthreads_example.txt"
    "/home/seed/Desktop/bcc/tools/dbslower_example.txt"
    "/home/seed/Desktop/bcc/tools/dbstat_example.txt"
    "/home/seed/Desktop/bcc/tools/dcsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/dcstat_example.txt"
    "/home/seed/Desktop/bcc/tools/deadlock_example.txt"
    "/home/seed/Desktop/bcc/tools/dirtop_example.txt"
    "/home/seed/Desktop/bcc/tools/drsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/execsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/exitsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/ext4dist_example.txt"
    "/home/seed/Desktop/bcc/tools/ext4slower_example.txt"
    "/home/seed/Desktop/bcc/tools/filelife_example.txt"
    "/home/seed/Desktop/bcc/tools/fileslower_example.txt"
    "/home/seed/Desktop/bcc/tools/filetop_example.txt"
    "/home/seed/Desktop/bcc/tools/funccount_example.txt"
    "/home/seed/Desktop/bcc/tools/funcinterval_example.txt"
    "/home/seed/Desktop/bcc/tools/funclatency_example.txt"
    "/home/seed/Desktop/bcc/tools/funcslower_example.txt"
    "/home/seed/Desktop/bcc/tools/gethostlatency_example.txt"
    "/home/seed/Desktop/bcc/tools/hardirqs_example.txt"
    "/home/seed/Desktop/bcc/tools/inject_example.txt"
    "/home/seed/Desktop/bcc/tools/javacalls_example.txt"
    "/home/seed/Desktop/bcc/tools/javaflow_example.txt"
    "/home/seed/Desktop/bcc/tools/javagc_example.txt"
    "/home/seed/Desktop/bcc/tools/javaobjnew_example.txt"
    "/home/seed/Desktop/bcc/tools/javastat_example.txt"
    "/home/seed/Desktop/bcc/tools/javathreads_example.txt"
    "/home/seed/Desktop/bcc/tools/killsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/klockstat_example.txt"
    "/home/seed/Desktop/bcc/tools/kvmexit_example.txt"
    "/home/seed/Desktop/bcc/tools/llcstat_example.txt"
    "/home/seed/Desktop/bcc/tools/mdflush_example.txt"
    "/home/seed/Desktop/bcc/tools/memleak_example.txt"
    "/home/seed/Desktop/bcc/tools/mountsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/mysqld_qslower_example.txt"
    "/home/seed/Desktop/bcc/tools/netqtop_example.txt"
    "/home/seed/Desktop/bcc/tools/nfsdist_example.txt"
    "/home/seed/Desktop/bcc/tools/nfsslower_example.txt"
    "/home/seed/Desktop/bcc/tools/nodegc_example.txt"
    "/home/seed/Desktop/bcc/tools/nodestat_example.txt"
    "/home/seed/Desktop/bcc/tools/offcputime_example.txt"
    "/home/seed/Desktop/bcc/tools/offwaketime_example.txt"
    "/home/seed/Desktop/bcc/tools/oomkill_example.txt"
    "/home/seed/Desktop/bcc/tools/opensnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/perlcalls_example.txt"
    "/home/seed/Desktop/bcc/tools/perlflow_example.txt"
    "/home/seed/Desktop/bcc/tools/perlstat_example.txt"
    "/home/seed/Desktop/bcc/tools/phpcalls_example.txt"
    "/home/seed/Desktop/bcc/tools/phpflow_example.txt"
    "/home/seed/Desktop/bcc/tools/phpstat_example.txt"
    "/home/seed/Desktop/bcc/tools/pidpersec_example.txt"
    "/home/seed/Desktop/bcc/tools/profile_example.txt"
    "/home/seed/Desktop/bcc/tools/pythoncalls_example.txt"
    "/home/seed/Desktop/bcc/tools/pythonflow_example.txt"
    "/home/seed/Desktop/bcc/tools/pythongc_example.txt"
    "/home/seed/Desktop/bcc/tools/pythonstat_example.txt"
    "/home/seed/Desktop/bcc/tools/readahead_example.txt"
    "/home/seed/Desktop/bcc/tools/reset-trace_example.txt"
    "/home/seed/Desktop/bcc/tools/rubycalls_example.txt"
    "/home/seed/Desktop/bcc/tools/rubyflow_example.txt"
    "/home/seed/Desktop/bcc/tools/rubygc_example.txt"
    "/home/seed/Desktop/bcc/tools/rubyobjnew_example.txt"
    "/home/seed/Desktop/bcc/tools/rubystat_example.txt"
    "/home/seed/Desktop/bcc/tools/runqlat_example.txt"
    "/home/seed/Desktop/bcc/tools/runqlen_example.txt"
    "/home/seed/Desktop/bcc/tools/runqslower_example.txt"
    "/home/seed/Desktop/bcc/tools/shmsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/slabratetop_example.txt"
    "/home/seed/Desktop/bcc/tools/sofdsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/softirqs_example.txt"
    "/home/seed/Desktop/bcc/tools/solisten_example.txt"
    "/home/seed/Desktop/bcc/tools/sslsniff_example.txt"
    "/home/seed/Desktop/bcc/tools/stackcount_example.txt"
    "/home/seed/Desktop/bcc/tools/statsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/swapin_example.txt"
    "/home/seed/Desktop/bcc/tools/syncsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/syscount_example.txt"
    "/home/seed/Desktop/bcc/tools/tclcalls_example.txt"
    "/home/seed/Desktop/bcc/tools/tclflow_example.txt"
    "/home/seed/Desktop/bcc/tools/tclobjnew_example.txt"
    "/home/seed/Desktop/bcc/tools/tclstat_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpaccept_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpconnect_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpconnlat_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpdrop_example.txt"
    "/home/seed/Desktop/bcc/tools/tcplife_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpretrans_example.txt"
    "/home/seed/Desktop/bcc/tools/tcprtt_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpstates_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpsubnet_example.txt"
    "/home/seed/Desktop/bcc/tools/tcpsynbl_example.txt"
    "/home/seed/Desktop/bcc/tools/tcptop_example.txt"
    "/home/seed/Desktop/bcc/tools/tcptracer_example.txt"
    "/home/seed/Desktop/bcc/tools/threadsnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/tplist_example.txt"
    "/home/seed/Desktop/bcc/tools/trace_example.txt"
    "/home/seed/Desktop/bcc/tools/ttysnoop_example.txt"
    "/home/seed/Desktop/bcc/tools/vfscount_example.txt"
    "/home/seed/Desktop/bcc/tools/vfsstat_example.txt"
    "/home/seed/Desktop/bcc/tools/virtiostat_example.txt"
    "/home/seed/Desktop/bcc/tools/wakeuptime_example.txt"
    "/home/seed/Desktop/bcc/tools/xfsdist_example.txt"
    "/home/seed/Desktop/bcc/tools/xfsslower_example.txt"
    "/home/seed/Desktop/bcc/tools/zfsdist_example.txt"
    "/home/seed/Desktop/bcc/tools/zfsslower_example.txt"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/seed/Desktop/bcc/build/tools/lib/cmake_install.cmake")
  include("/home/seed/Desktop/bcc/build/tools/old/cmake_install.cmake")

endif()

