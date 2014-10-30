//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package test;

import org.omnetpp.queueing.MultigateQueue;
import org.omnetpp.queueing.MyQueue;
import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network Network
{
    @display("bgb=723,462");
    submodules:
        source: Source {
            @display("p=127,98");
        }
        ActiveQueue1: Queue {
            @display("p=330,118");
        }
        ActiveQueue2: Queue {
            @display("p=462,118");
        }
        sink: Sink {
            @display("p=683,212");
        }
        myQueue: MyQueue {
            @display("p=208,338");
        }
        multigateQueue: MultigateQueue {
            @display("p=478,326");
        }
    connections:
        ActiveQueue1.out --> ActiveQueue2.in++;
        ActiveQueue2.out --> multigateQueue.inEnd;
        source.out --> myQueue.in++;
        myQueue.out --> multigateQueue.inSource;
        multigateQueue.out --> ActiveQueue1.in++;
        multigateQueue.outSink --> sink.in++;
}

