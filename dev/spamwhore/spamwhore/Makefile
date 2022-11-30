#
# SpamWhore, more info see README, COPYRIGHT and CHANGELOG files
#

INSTALL?=/usr/bin/install
QMAIL_PREFIX?=/var/qmail
PREFIX?=/usr/local
LOCALBASE?=/usr/local
TOUCH?=touch
CHMOD?=chmod
CHOWN?=chown
RM?=rm
ECHO?=echo

all: install-vpopmail

install-vpopmail:
	${INSTALL} -o vpopmail -g vchkpw -m 500 vpopmail/spamwhore ${PREFIX}/vpopmail/bin/ \
	&& ${TOUCH} /var/log/maildrop-spamwhore.log && ${CHOWN} vpopmail /var/log/maildrop-spamwhore.log \
           && ${CHMOD} 740 /var/log/maildrop-spamwhore.log \
	      && ${INSTALL} -o root -g wheel -m 555 vpopmail/subscribeIMAP.sh ${PREFIX}/vpopmail/bin/ 

deinstall:
	${RM} -f  ${PREFIX}/vpopmail/bin/spamwhore ${PREFIX}/vpopmail/bin//subscribeIMAP.sh \
		/var/log/maildrop-spamwhore.log

