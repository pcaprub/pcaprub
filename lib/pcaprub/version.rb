module PCAPRUB #:nodoc:
  
  module VERSION #:nodoc:
    
    MAJOR = 0
<<<<<<< HEAD
    MINOR = 11
    TINY = 0 
=======
    MINOR = 10
    TINY = 1
>>>>>>> 36e6320f4af8f2bef761c82177eb86fb2cac15c9

    STRING = [MAJOR, MINOR, TINY].join('.')
    
  end
  class Pcap
    def self.version 
      return PCAPRUB::VERSION::STRING
    end
  end
  
end  
