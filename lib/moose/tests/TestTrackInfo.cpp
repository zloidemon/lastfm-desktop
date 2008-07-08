/***************************************************************************
 *   Copyright (C) 2005 - 2007 by                                          *
 *      Last.fm Ltd <client@last.fm>                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Steet, Fifth Floor, Boston, MA  02110-1301, USA.          *
 ***************************************************************************/

#include <QtTest/QtTest>
#include <QMainWindow>

#include "lib/unicorn/Track.h"

class TestTrack : public QObject
{
    Q_OBJECT

    private slots:
        void initTestCase()
        {
            // doing nothing
        }
        
        void testArtist();
        void testArtist_data();
        
        void testAlbum();
        void testAlbum_data();
        
        void testTrack();
        void testTrack_data();
        
        void testTrackNumber();
        void testPlayCount();
        void testDuration();
        void testMbId();
        void testPath();
        void testSource();
        void testRatingFlag();
        
        void testPlayerId();
        void testPlayerId_data();
        
        void testFpId();
        void testFpId_data();
        
        void testDomConstructor();
};

void
TestTrack::testArtist()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    QFETCH( QString, string );
    QFETCH( QString, result );
    
    mutableTrack.setArtist( string );
    
    QCOMPARE( track.artist(), result );
}

void
TestTrack::testArtist_data()
{
    QTest::addColumn<QString>( "string" );
    QTest::addColumn<QString>( "result" );

    QTest::newRow( "regular" )   << "Monkey-pink" << "Monkey-pink";
    QTest::newRow( "mixed" )     << "" << "";
    QTest::newRow( "unicode" )   << QString( "佐橋俊彦asdf ケリー・チャン 78654" ) << QString( "佐橋俊彦asdf ケリー・チャン 78654" );
}

void
TestTrack::testAlbum()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    QFETCH( QString, string );
    QFETCH( QString, result );
    
    mutableTrack.setAlbum( string );
    
    QCOMPARE( track.album(), result );
}

void
TestTrack::testAlbum_data()
{
    QTest::addColumn<QString>( "string" );
    QTest::addColumn<QString>( "result" );

    QTest::newRow( "regular" )   << "Mozart" << "Mozart";
    QTest::newRow( "mixed" )     << "" << "";
    QTest::newRow( "unicode" )   << QString( "佐橋俊彦asdf ケリー・チャン 78654" ) << QString( "佐橋俊彦asdf ケリー・チャン 78654" );
}

void
TestTrack::testTrack()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    QFETCH( QString, string );
    QFETCH( QString, result );
    
    mutableTrack.setTrack( string );
    
    QCOMPARE( track.track(), result );
}

void
TestTrack::testTrack_data()
{
    QTest::addColumn<QString>( "string" );
    QTest::addColumn<QString>( "result" );

    QTest::newRow( "regular" )   << "Mozart" << "Mozart";
    QTest::newRow( "mixed" )     << "" << "";
    QTest::newRow( "unicode" )   << QString( "佐橋俊彦asdf ケリー・チャン 78654" ) << QString( "佐橋俊彦asdf ケリー・チャン 78654" );
}

void
TestTrack::testTrackNumber()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    mutableTrack.setTrackNumber( -1 );
    QCOMPARE( track.trackNumber(), -1 );
    
    mutableTrack.setTrackNumber( 0 );
    QCOMPARE( track.trackNumber(), 0 );
    
    mutableTrack.setTrackNumber( 11 );
    QCOMPARE( track.trackNumber(), 11 );
    
    mutableTrack.setTrackNumber( 812736 );
    QCOMPARE( track.trackNumber(), 812736 );
}

void
TestTrack::testPlayCount()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    mutableTrack.setPlayCount( -1 );
    QCOMPARE( track.playCount(), -1 );
    
    mutableTrack.setPlayCount( 0 );
    QCOMPARE( track.playCount(), 0 );
    
    mutableTrack.setPlayCount( 11 );
    QCOMPARE( track.playCount(), 11 );
    
    mutableTrack.setPlayCount( 812736 );
    QCOMPARE( track.playCount(), 812736 );
}

void
TestTrack::testDuration()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    mutableTrack.setDuration( -1 );
    QCOMPARE( track.duration(), -1 );
    
    mutableTrack.setDuration( 0 );
    QCOMPARE( track.duration(), 0 );
    
    mutableTrack.setDuration( 11 );
    QCOMPARE( track.duration(), 11 );
    
    mutableTrack.setDuration( 812736 );
    QCOMPARE( track.duration(), 812736 );
}

void
TestTrack::testMbId()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    mutableTrack.setMbId( "kk83842736487236whatever" );
    QCOMPARE( track.mbId(), QString( "kk83842736487236whatever" ) );
    
    mutableTrack.setMbId( "" );
    QCOMPARE( track.mbId(), QString( "" ) );
    
    mutableTrack.setMbId( "=-123-890456'kÚÅÎÔÎca" );
    QCOMPARE( track.mbId(), QString( "=-123-890456'kÚÅÎÔÎca" ) );
}

void
TestTrack::testPath()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    mutableTrack.setPath( "http://ws.last.fm/the/path/to/the/ws/that/we/caer/aboutsedr" );
    QCOMPARE( track.path(), QString( "http://ws.last.fm/the/path/to/the/ws/that/we/caer/aboutsedr" ) );
    
    mutableTrack.setPath( "" );
    QCOMPARE( track.path(), QString( "" ) );
    
    mutableTrack.setPath( "C:\\local\\file.mp3" );
    QCOMPARE( track.path(), QString( "C:\\local\\file.mp3" ) );
    
    mutableTrack.setPath( "29347892374" );
    QCOMPARE( track.path(), QString( "29347892374" ) );
}

void
TestTrack::testSource()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    mutableTrack.setSource( Track::Radio );
    QCOMPARE( track.source(), Track::Radio );
    QCOMPARE( track.sourceString(), QString( "L" ) );
    
    mutableTrack.setSource( Track::Unknown );
    QCOMPARE( track.source(), Track::Unknown );
    QCOMPARE( track.sourceString(), QString( "U" ) );
    
    mutableTrack.setSource( Track::MediaDevice );
    QCOMPARE( track.source(), Track::MediaDevice );
    QCOMPARE( track.sourceString(), QString( "P" ) );
    
    mutableTrack.setSource( Track::Player );
    QCOMPARE( track.source(), Track::Player );
    QCOMPARE( track.sourceString(), QString( "P" ) );
}

void
TestTrack::testRatingFlag()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    QCOMPARE( track.ratingCharacter(), QString( "" ) );
    QVERIFY( !track.isSkipped() );
    QVERIFY( !track.isLoved() );
    QVERIFY( !track.isBanned() );
    QVERIFY( !track.isScrobbled() );
    
    // simple checking
    mutableTrack.setRatingFlag( Track::Skipped );
    QCOMPARE( track.ratingCharacter(), QString( "S" ) );
    QVERIFY( track.isSkipped() );
    
    mutableTrack.setRatingFlag( Track::Scrobbled );
    QCOMPARE( track.ratingCharacter(), QString( "" ) );
    QVERIFY( track.isScrobbled() );
    
    mutableTrack.setRatingFlag( Track::Loved );
    QCOMPARE( track.ratingCharacter(), QString( "L" ) );
    QVERIFY( track.isLoved() );
    
    mutableTrack.setRatingFlag( Track::Banned );
    QCOMPARE( track.ratingCharacter(), QString( "B" ) );
    QVERIFY( track.isBanned() );
    
    
    Track track2;
    MutableTrack mutableTrack2( track2 );
    
    // somewhat less simple checking
    mutableTrack2.setRatingFlag( Track::Skipped );
    QCOMPARE( track2.ratingCharacter(), QString( "S" ) );
    QVERIFY( track2.isSkipped() );
    
    mutableTrack2.setRatingFlag( Track::Loved );
    QCOMPARE( track2.ratingCharacter(), QString( "L" ) );
    QVERIFY( track2.isLoved() );
    QVERIFY( track2.isSkipped() );
    
    mutableTrack2.setRatingFlag( Track::Scrobbled );
    QCOMPARE( track2.ratingCharacter(), QString( "L" ) );
    QVERIFY( track2.isScrobbled() );
    QVERIFY( track2.isSkipped() );
    QVERIFY( track2.isLoved() );
}

void
TestTrack::testPlayerId()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    QFETCH( QString, string );
    QFETCH( QString, result );
    
    mutableTrack.setPlayerId( string );
    
    QCOMPARE( track.playerId(), result );
}

void
TestTrack::testPlayerId_data()
{
    QTest::addColumn<QString>( "string" );
    QTest::addColumn<QString>( "result" );

    QTest::newRow( "regular" )   << "Mozart" << "Mozart";
    QTest::newRow( "mixed" )     << "" << "";
    QTest::newRow( "unicode" )   << QString( "佐橋俊彦asdf ケリー・チャン 78654" ) << QString( "佐橋俊彦asdf ケリー・チャン 78654" );
}

void
TestTrack::testFpId()
{
    Track track;
    MutableTrack mutableTrack( track );
    
    QFETCH( QString, string );
    QFETCH( QString, result );
    
    mutableTrack.setFpId( string );
    
    QCOMPARE( track.fpId(), result );
}

void
TestTrack::testFpId_data()
{
    QTest::addColumn<QString>( "string" );
    QTest::addColumn<QString>( "result" );

    QTest::newRow( "regular" )   << "Mozart" << "Mozart";
    QTest::newRow( "mixed" )     << "" << "";
    QTest::newRow( "unicode" )   << QString( "佐橋俊彦asdf ケリー・チャン 78654" ) << QString( "佐橋俊彦asdf ケリー・チャン 78654" );
}

void
TestTrack::testDomConstructor()
{
    QEXPECT_FAIL( "", "A test for constructing a track-info from a dom-element has not yet been implemented", Continue );
    QVERIFY( false );
}

// Appless is faster, and there is no need for a QApplication in this test
QTEST_APPLESS_MAIN(TestTrack)
#include "TestTrack.moc"

