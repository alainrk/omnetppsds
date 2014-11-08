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
import org.omnetpp.queueing.Allocate;
import org.omnetpp.queueing.Deallocate;
import org.omnetpp.queueing.Delay;
import org.omnetpp.queueing.MultigateQueue;
import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.ResourcePool;
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
        router: Router {
            @display("p=280,295");
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
        Terminals: Delay {
            @display("p=280,120");
        }
        allocate: Allocate {
            @display("p=108,295");
        }
        deallocate: Deallocate {
            @display("p=280,209");
        }
        pota: ResourcePool {
            @display("p=178,373");
        }
    connections:
        router.out++ --> queue1.in++;
        router.out++ --> queue2.in++;
        router.out++ --> queue3.in++;
        router.out++ --> queue4.in++;
        queue1.out --> router.in++;
        queue2.out --> router.in++;
        queue3.out --> router.in++;
        queue4.out --> router.in++;
        sourceOnce.out --> Terminals.in++;
        router.out++ --> deallocate.in++;
        deallocate.out --> Terminals.in++;
        Terminals.out --> allocate.in++;
        allocate.out --> router.in++;
}
