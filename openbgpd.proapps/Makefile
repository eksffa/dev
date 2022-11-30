# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD: ports/net/openbgpd/Makefile,v 1.35 2012/12/24 12:56:29 svnexp Exp $

PORTNAME=	openbgpd
PORTVERSION=	5.2.20121209
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenBGPD
DISTNAME=	${PORTNAME}-4.6
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

LICENSE=	ISCL
LICENSE_FILE=	${FILESDIR}/COPYING

CONFLICTS=	zebra-[0-9]* quagga-[0-9]*

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
MAKE_ARGS=	-DFREEBSDPORTS
USES=		uidfix
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	sbin/bgpctl sbin/bgpd
SUB_FILES=	pkg-message
USERS=		_bgpd
GROUPS=		_bgpd

MAN5=		bgpd.conf.5
MAN8=		bgpctl.8 bgpd.8

OPTIONS_DEFINE=	IPV6LLPEER ASIN
OPTIONS_DEFAULT=IPV6LLPEER
IPV6LLPEER_DESC=Support nexthop using IPv6 link-local address
ASIN_DESC=Add allowas-in support from ProApps

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6LLPEER}
MAKE_ARGS+=	-DIPV6_LINKLOCAL_PEER
.endif

post-patch:
.if ${PORT_OPTIONS:MASIN}
	@${PATCH} -s -d ${WRKSRC} < ${FILESDIR}/local-patch-openbgpd-allowas-in.c
.endif
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
		${WRKSRC}/bgpd/bgpd.8			\
		${WRKSRC}/bgpd/bgpd.conf.5		\
		${WRKSRC}/bgpctl/bgpctl.8

.include <bsd.port.mk>
