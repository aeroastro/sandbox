# frozen_string_literal: true

require 'mysql2'
require 'yaml'

class ClientPool
  YAML_PATH = 'database.yml'

  def self.client_class
    Mysql2::Client
  end

  def initialize(options = {})
    @options = YAML.safe_load(File.read(YAML_PATH)).tap do |opt|
      options.each { |k, v| opt[k.to_s] = v }
    end
  end

  def with_clients(&block)
    clients = Array.new(block.arity) { self.class.client_class.new(@options) }
    yield(*clients)
  ensure
    clients&.each(&:close)
  end
end
