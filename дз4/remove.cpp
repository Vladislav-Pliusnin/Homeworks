struct LineNotFound : DomainError {
    std::int64_t request_id;
    std::int64_t line_id;
    LineNotFound(std::int64_t req_id, std::int64_t l_id) : DomainError("Line not found"), request_id(req_id), line_id(l_id) {}
};

struct RequestNotDraft : DomainError {
    std::int64_t request_id;
    RequestNotDraft(std::int64_t req_id) : DomainError("Request is not a draft"), request_id(req_id) {}
};

void PurchaseRequest::remove_line(LineId id) {
    require_draft(); 
    auto it = std::find_if(lines.begin(), lines.end(), 
        [id](const RequestLine& line) { return line.get_id() == id; });
    
    if (it == lines.end()) {
        throw LineNotFound(id_.value, id.value);
    }

    lines.erase(it);
}