import org.w3c.dom.traversal.NodeFilter;
import org.w3c.dom.*;

public class RSSFilter implements NodeFilter{

    /**
    * Defines which node will be allowed to be added.
    *
    * @param node the current node from the NodeIterator
    *
    */
    public short acceptNode(Node node){
	
	Element candidate = (Element) node;

	String name = candidate.getNodeName();

	if(name.equals("title")||name.equals("pubDate")||name.equals("description")){
	    Node parent = node.getParentNode();
	    if("item".equals(parent.getNodeName()))
	     return FILTER_ACCEPT;
	}

	return FILTER_SKIP;
    }
}
