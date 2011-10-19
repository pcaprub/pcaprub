
module PCAPRUB
  # The base exception for JSON errors.
  class PCAPRUBError < StandardError; end

  # This exception is raised, if a parser error occurs.
  class BindingError < PCAPRUBError; end

  # This exception is raised, if the nesting of parsed datastructures is too
  # deep.
  class BPFError < PCAPRUBError; end

end

