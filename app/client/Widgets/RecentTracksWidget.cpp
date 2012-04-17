
#include <QWidget>
#include <QLayoutItem>
#include <QDebug>

#include <lastfm/Track.h>

#include "lib/unicorn/layouts/SideBySideLayout.h"

#include "ScrobblesWidget.h"
#include "TrackWidget.h"
#include "MetadataWidget.h"

#include "RecentTracksWidget.h"


RecentTracksWidget::RecentTracksWidget( QWidget* parent )
    :QWidget( parent )
{
    m_layout = new SideBySideLayout();
    setLayout( m_layout );
    m_layout->addWidget( m_scrobbles = new ScrobblesWidget );

    connect( m_scrobbles, SIGNAL( trackClicked(TrackWidget&)), SLOT( onTrackClicked(TrackWidget&)));
    connect( m_layout, SIGNAL( moveFinished(QLayoutItem*)), SLOT(onMoveFinished(QLayoutItem*)));
}

void
RecentTracksWidget::refresh()
{
    m_scrobbles->refresh();
}

void
RecentTracksWidget::onCurrentChanged( int index )
{
    if ( index == 1 )
        m_scrobbles->refresh(); // this tab was clicked on

    m_layout->moveToWidget( m_scrobbles );
}

void
RecentTracksWidget::onTrackClicked( TrackWidget& trackWidget )
{
    MetadataWidget* w;
    m_layout->addWidget( w = new MetadataWidget( trackWidget.track() ));
    w->fetchTrackInfo();
    w->setBackButtonVisible( true );

    trackWidget.startSpinner();
    connect( m_layout, SIGNAL( moveFinished(QLayoutItem*)), &trackWidget, SLOT(clearSpinner()) );

    connect( w, SIGNAL(finished()), SLOT(onMetadataWidgetFinished()));
    connect( w, SIGNAL(backClicked()), SLOT(onBackClicked()));
}

void
RecentTracksWidget::onMetadataWidgetFinished()
{
    m_layout->moveForward();
}

void
RecentTracksWidget::onBackClicked()
{
    m_layout->moveToWidget( m_scrobbles );
}

void
RecentTracksWidget::onMoveFinished( QLayoutItem* i )
{
    if( i->widget() == m_scrobbles )
    {
        while ( m_layout->count() > 1 )
        {
            QLayoutItem* item = m_layout->takeAt( 1 );
            item->widget()->deleteLater();
            delete item;
        }
    }
}
