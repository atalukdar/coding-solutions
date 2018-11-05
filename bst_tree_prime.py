#
# Complete the 'primeQuery' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY first
#  3. INTEGER_ARRAY second
#  4. INTEGER_ARRAY values
#  5. INTEGER_ARRAY queries
#

class mtree:
    def __init__(self):
        self.level = None
        self.node_num = None
        self.children = []
        self.data = None
        self.sum_prime = None
        
    def calc_sum_prime():
        
        if self.sum_prime is not None:
            return self.sum_prime 
        
        else if(len(self.children) == 0 ):
            if(isprime(self.data)):
                return 1
            else:
                return 0
        else:
            calc_sum = 0
            for child in children:
                calc_sum = calc_sum + calc_sum_prime(child)
            self.sum_prime = calc_sum
            return calc_sum
    
    def add_edge(self, new_child):
        self.children.append(new_child)
    
    def remove_edge(self, remove_child):
        self.children.remove(remove_child)
        
        
        
def number_all_levels(mtree m1, int level):
    m1.level = level
    curr_level  = level + 1
    if(len(m1.children == 0)):
        
    for child in m1.children:
        if(child.level is not None):
            number_all_levels(child, curr_level)
        else:
            child.remove_edge(m1.node_num)
            
    
    
        
        

def primeQuery(n, first, second, values, queries):
    mtree mytree = [];
    for i in range(n):
	mtree[i] = Mtree()
        mytree[i].data = values[i]
        mytree[i].node_num = i
    num_edges = len(first)
    for j in range(num_edges):
        e1 = first[j]
        e2 = second[j]
        mytree[e1].add_edge(e2)
        mytree[e2].add_edge(e1)
    number_all_levels(mtree mytree[0], curr_level = 0)
    
        

    # Write your code here


