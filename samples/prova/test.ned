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

package prova;
import org.omnetpp.queueing.*;
//
// TODO documentation
//
network pesce
{
    @display("bgb=745,458");
    submodules:
        source: Source {
            @display("p=83,176");
        }
        sink: Sink {
            @display("p=690,176");
        }
        queue: Queue {
            @display("p=260,162");
        }
        queue1: Queue {
            @display("p=487,176");
        }
        myQueue: MyQueue {
            @display("p=360,296");
        }
    connections:
        queue.out --> queue1.in++;
        source.out --> myQueue.in++;
        myQueue.out --> queue.in++;
        queue1.out --> sink.in++;
}

