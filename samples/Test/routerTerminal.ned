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
import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.SourceOnce;


//
// TODO documentation
//
network Network1
{
    @display("bgb=813,468");
    submodules:
        sourceOnce: SourceOnce {
            @display("p=139,81");
        }
        queue: Queue {
            @display("p=139,217");
        }
        router: Router {
            @display("p=284,217");
        }
        queue1: Queue {
            @display("p=463,139");
        }
        queue2: Queue {
            @display("p=469,196");
        }
        queue3: Queue {
            @display("p=469,256");
        }
        queue4: Queue {
            @display("p=462,319");
        }
        Terminal: Queue {
            @display("p=284,127");
        }
    connections:
        sourceOnce.out --> Terminal.in++;
        Terminal.out --> queue.in++;
        queue.out --> router.in++;
        router.out++ --> Terminal.in++;
        router.out++ --> queue1.in++;
        router.out++ --> queue2.in++;
        router.out++ --> queue3.in++;
        router.out++ --> queue4.in++;
        queue1.out --> router.in++;
        queue2.out --> router.in++;
        queue3.out --> router.in++;
        queue4.out --> router.in++;
}

